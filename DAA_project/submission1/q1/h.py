import random
def maj(c):
    if len(c)==1:return c[0]
    m=len(c)//2
    for x in(maj(c[:m]),maj(c[m:])):
        if x is not None and c.count(x)>len(c)/2:return x
def localmin(t):
    i=1
    while 2*i<len(t):
        m=min((2*i,2*i+1),key=lambda j:t[j])
        if t[i]<t[m]:break
        i=m
    return i
def peak(a):
    lo,hi=0,len(a)-1
    while lo<hi:
        m=(lo+hi)//2
        if a[m]<a[m+1]:lo=m+1
        else:hi=m
    return lo
n=int(input())
c=[random.randint(1,3) for _ in range(n)]
print(maj(c))
t=[0]+random.sample(range(10*n),2**n.bit_length()-1)
i=localmin(t)
print(i,t[i],t[i//2],t[2*i:2*i+2])
k=random.randint(1,n-2)
a=sorted(random.sample(range(n),k))+sorted(random.sample(range(n,2*n),n-k),reverse=True)
print(peak(a),a.index(max(a)))