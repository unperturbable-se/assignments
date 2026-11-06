import random
def sig(a):
    if len(a)<2:return a,0
    l,x=sig(a[:len(a)//2])
    r,y=sig(a[len(a)//2:])
    t=x+y
    i=0
    for b in r:
        while i<len(l) and l[i]<=2*b:i+=1
        t+=len(l)-i
    return sorted(l+r),t
n=int(input())
a=[random.randint(1,10*n) for _ in range(n)]
print(sig(a)[1],sum(a[i]>2*a[j] for i in range(n) for j in range(i+1,n)))