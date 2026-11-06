import random
def median(A,B):
    la=lb=0
    m=len(A)
    while m>1:
        k=m//2
        if A[la+k-1]<B[lb+k-1]:la+=k
        else:lb+=k
        m-=k
    return min(A[la],B[lb])
n=int(input())
v=random.sample(range(10*n),2*n)
print(median(sorted(v[:n]),sorted(v[n:])),sorted(v)[n-1])