from math import dist
from pathlib import Path

from fastapi import FastAPI
from fastapi.middleware.cors import CORSMiddleware
from fastapi.responses import FileResponse
from fastapi.staticfiles import StaticFiles

BASE_DIR   = Path(__file__).resolve().parent
DATA_DIR   = BASE_DIR.parent / "q2" / "data"   # keep your existing layout
STATIC_DIR = BASE_DIR / "static"

app = FastAPI(title="Divide & Conquer Visualizer")

# --- CORS: fully open for every origin / method / header ---------------
app.add_middleware(
    CORSMiddleware,
    allow_origins=["*"],        # any origin (including file:// null)
    allow_credentials=False,    # must be False when origins == ["*"]
    allow_methods=["*"],
    allow_headers=["*"],
    expose_headers=["*"],
    max_age=86400,
)

# --- API -----------------------------------------------------------------
def closest_pair(points):
    half = len(points) // 2
    if len(points) <= 3:
        return min((dist(a, b), (a, b)) for i, a in enumerate(points) for b in points[i + 1:])
    best = min(closest_pair(points[:half]), closest_pair(points[half:]))
    mid_x = points[half][0]
    strip = sorted((p for p in points if abs(p[0] - mid_x) < best[0]), key=lambda p: p[1])
    for i, a in enumerate(strip):
        for b in strip[i + 1:i + 8]:
            best = min(best, (dist(a, b), (a, b)))
    return best


def karatsuba(a, b):
    if abs(a) < 10 or abs(b) < 10:
        return a * b
    split = 10 ** (max(len(str(abs(a))), len(str(abs(b)))) // 2)
    a_high, a_low = divmod(a, split)
    b_high, b_low = divmod(b, split)
    low, high = karatsuba(a_low, b_low), karatsuba(a_high, b_high)
    mid = karatsuba(a_high + a_low, b_high + b_low) - low - high
    return high * split * split + mid * split + low


@app.get("/files")
def list_files():
    return sorted((f.name for f in DATA_DIR.glob("*.txt")), key=lambda n: (len(n), n))


@app.get("/closest/{name}")
def closest(name):
    with open(DATA_DIR / Path(name).name) as f:
        points = sorted(tuple(map(int, line.split())) for line in f)
    distance, pair = closest_pair(points)
    return {"points": points, "distance": distance, "pair": pair}


@app.get("/mult/{name}")
def multiply(name):
    with open(DATA_DIR / Path(name).name) as f:
        a, b = map(int, f.read().split())
    return {"a": str(a), "b": str(b), "product": str(karatsuba(a, b))}


@app.get("/health")
def health():
    return {"ok": True, "static": STATIC_DIR.is_dir(), "data": DATA_DIR.is_dir()}


# --- Static UI ----------------------------------------------------------
# Mounted last so it never shadows the API routes above.
app.mount("/static", StaticFiles(directory=STATIC_DIR), name="static")


@app.get("/", include_in_schema=False)
def index():
    return FileResponse(STATIC_DIR / "index.html")