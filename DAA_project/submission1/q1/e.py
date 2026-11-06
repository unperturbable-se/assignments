import random
def f(a):
    if len(a)<2:return float("inf")
    lo,hi=min(a),max(a)
    if lo==hi:return 0
    l=[x for x in a if x<=(lo+hi)/2]
    r=[x for x in a if x>(lo+hi)/2]
    return min(f(l),f(r),min(r)-max(l))
n=int(input())
a=random.sample(range(10*n),n)
print(f(a))