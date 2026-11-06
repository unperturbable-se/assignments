import random
def qs(a):
    if len(a)<2:return a,0
    p,r=a[0],a[1:]
    l,x=qs([i for i in r if i<p])
    g,y=qs([i for i in r if i>=p])
    return l+[p]+g,x+y+len(r)
n=int(input())
a=random.sample(range(10*n),n)
print(qs(a)[1],qs(sorted(a))[1])