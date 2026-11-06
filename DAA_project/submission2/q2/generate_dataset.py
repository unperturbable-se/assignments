import random
for i in range(1,11):
    with open(f"data/closest_{i}.txt","w") as f:
        for _ in range(100+100*i):f.write(f"{random.randint(-10000,10000)} {random.randint(-10000,10000)}\n")
    with open(f"data/mult_{i}.txt","w") as f:
        f.write(f"{random.randint(10**(100*i),10**(100*i+50))} {random.randint(10**(100*i),10**(100*i+50))}\n")