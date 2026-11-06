import sys
def k(a,b):
    if abs(a)<10 or abs(b)<10:return a*b
    t=10**(max(len(str(abs(a))),len(str(abs(b))))//2)
    ah,al=divmod(a,t)
    bh,bl=divmod(b,t)
    z0,z2=k(al,bl),k(ah,bh)
    return z2*t*t+(k(ah+al,bh+bl)-z0-z2)*t+z0
a,b=map(int,open(sys.argv[1]).read().split())
print(k(a,b)==a*b)