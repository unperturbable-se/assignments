// Same-origin when served by FastAPI; harmless fallback if opened as a file.
const API = location.protocol === "file:" ? "http://127.0.0.1:8000" : "";
const $ = (id) => document.getElementById(id);
const state = { files: [], result: null, splits: [], timer: null };

async function getJSON(url) {
  const response = await fetch(API + url);
  if (!response.ok) throw new Error(`Request failed (${response.status})`);
  return response.json();
}

function fillFileSelect() {
  const prefix = $("algo").value + "_";
  const names = state.files.filter((name) => name.startsWith(prefix));
  $("file").replaceChildren(...names.map((name) => new Option(name, name)));
}

function showView() {
  const isClosest = $("algo").value === "closest";
  $("closest-view").classList.toggle("hidden", !isClosest);
  $("mult-view").classList.toggle("hidden", isClosest);
}

function renderRows(container, items) {
  container.replaceChildren(
    ...items.map(([label, value, style = ""]) => {
      const row = document.createElement("div");
      row.className = `row ${style}`;
      const name = document.createElement("span");
      name.className = "label";
      name.textContent = label;
      const content = document.createElement("code");
      content.textContent = value;
      row.append(name, content);
      return row;
    })
  );
}

function collectSplits(points, depth = 0, splits = []) {
  if (points.length <= 3) return splits;
  const mid = points.length >> 1;
  splits.push({ x: points[mid][0], depth });
  collectSplits(points.slice(0, mid), depth + 1, splits);
  collectSplits(points.slice(mid), depth + 1, splits);
  return splits;
}

function makeProjector(points, width, height, pad) {
  const xs = points.map((p) => p[0]);
  const ys = points.map((p) => p[1]);
  const [minX, maxX] = [Math.min(...xs), Math.max(...xs)];
  const [minY, maxY] = [Math.min(...ys), Math.max(...ys)];
  return {
    x: (v) => pad + ((v - minX) / (maxX - minX || 1)) * (width - 2 * pad),
    y: (v) => height - pad - ((v - minY) / (maxY - minY || 1)) * (height - 2 * pad),
  };
}

function drawCircle(ctx, x, y, radius, color) {
  ctx.fillStyle = color;
  ctx.beginPath();
  ctx.arc(x, y, radius, 0, Math.PI * 2);
  ctx.fill();
}

function drawClosest() {
  const { points, pair } = state.result;
  const level = Number($("depth").value);
  const canvas = $("plot");
  const ctx = canvas.getContext("2d");
  const project = makeProjector(points, canvas.width, canvas.height, 30);

  ctx.clearRect(0, 0, canvas.width, canvas.height);
  state.splits.filter((s) => s.depth < level).forEach((s) => {
    ctx.strokeStyle = `hsla(${210 + s.depth * 30}, 80%, 65%, 0.45)`;
    ctx.lineWidth = Math.max(1, 3 - s.depth * 0.4);
    ctx.beginPath();
    ctx.moveTo(project.x(s.x), 0);
    ctx.lineTo(project.x(s.x), canvas.height);
    ctx.stroke();
  });
  points.forEach(([x, y]) => drawCircle(ctx, project.x(x), project.y(y), 3, "#8a93ad"));
  drawPair(ctx, project, pair);
}

function drawPair(ctx, project, pair) {
  const [a, b] = pair.map(([x, y]) => [project.x(x), project.y(y)]);
  ctx.strokeStyle = "#ff5c7a";
  ctx.lineWidth = 2;
  ctx.beginPath();
  ctx.moveTo(...a);
  ctx.lineTo(...b);
  ctx.stroke();
  drawCircle(ctx, ...a, 6, "#ff5c7a");
  drawCircle(ctx, ...b, 6, "#ff5c7a");
}

function renderClosest(data) {
  state.result = data;
  state.splits = collectSplits(data.points);
  const maxDepth = Math.max(...state.splits.map((s) => s.depth), 0) + 1;
  $("depth").max = maxDepth;
  $("depth").value = 0;
  $("depth-label").textContent = 0;
  renderRows($("closest-stats"), [
    ["Number of points", data.points.length],
    ["Recursion depth", maxDepth],
    ["Closest pair", data.pair.map((p) => `(${p})`).join("  and  "), "highlight"],
    ["Distance", data.distance.toFixed(4), "good"],
  ]);
  drawClosest();
}

function togglePlay() {
  if (state.timer) return stopPlay();
  const slider = $("depth");
  slider.value = 0;
  $("play").textContent = "Pause";
  state.timer = setInterval(() => {
    if (Number(slider.value) >= Number(slider.max)) return stopPlay();
    slider.stepUp();
    slider.dispatchEvent(new Event("input"));
  }, 700);
}

function stopPlay() {
  clearInterval(state.timer);
  state.timer = null;
  $("play").textContent = "Play";
}

function renderMult({ a, b, product }) {
  const A = BigInt(a);
  const B = BigInt(b);
  const half = Math.floor(Math.max(a.length, b.length) / 2);
  const split = 10n ** BigInt(half);
  const [aHigh, aLow, bHigh, bLow] = [A / split, A % split, B / split, B % split];
  const high = aHigh * bHigh;
  const low = aLow * bLow;
  const mid = (aHigh + aLow) * (bHigh + bLow) - high - low;
  const result = high * split * split + mid * split + low;
  const match = result.toString() === product;

  renderRows($("mult-steps"), [
    ["a", a], ["b", b],
    ["Digits of a / b", `${a.length} / ${b.length}`],
    ["Split at", `10^${half}`],
    ["a high / a low", `${aHigh} / ${aLow}`],
    ["b high / b low", `${bHigh} / ${bLow}`],
    ["z2 = a high x b high", high.toString(), "highlight"],
    ["z0 = a low x b low", low.toString(), "highlight"],
    ["z1 = (aH+aL)(bH+bL) - z2 - z0", mid.toString(), "highlight"],
    ["z2*10^(2h) + z1*10^h + z0", result.toString()],
    ["Server product", product],
    ["Verification", match ? "Match: 3 multiplications used instead of 4" : "Mismatch", match ? "good" : "bad"],
  ]);
}

async function run() {
  const algo = $("algo").value;
  const file = $("file").value;
  $("status").textContent = "Running...";
  try {
    const data = await getJSON(`/${algo}/${file}`);
    algo === "closest" ? renderClosest(data) : renderMult(data);
    $("status").textContent = "";
  } catch (error) {
    $("status").textContent = error.message;
  }
}

$("algo").addEventListener("change", () => { fillFileSelect(); showView(); });
$("run").addEventListener("click", run);
$("play").addEventListener("click", togglePlay);
$("depth").addEventListener("input", () => {
  $("depth-label").textContent = $("depth").value;
  if (state.result) drawClosest();
});

getJSON("/files").then((files) => { state.files = files; fillFileSelect(); });