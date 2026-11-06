
def power(a,n):
    if n==0: return 1
    half=power(a,n//2);
    if n%2==0: return half*half
    return a*half*half

print(power(5,6))