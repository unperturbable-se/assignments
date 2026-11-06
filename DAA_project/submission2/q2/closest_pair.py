import sys
from math import dist
def cp(p):
    if len(p)<=3:return min(dist(a,b) for i,a in enumerate(p) for b in p[i+1:])
    x=p[len(p)//2][0]
    d=min(cp(p[:len(p)//2]),cp(p[len(p)//2:]))
    s=sorted((q for q in p if abs(q[0]-x)<d),key=lambda q:q[1])
    for i,a in enumerate(s):
        for b in s[i+1:i+8]:d=min(d,dist(a,b))
    return d
p=sorted(tuple(map(int,l.split())) for l in open(sys.argv[1]))
print(cp(p))