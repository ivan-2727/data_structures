mod = int(1e18)+7
base = 31

def string_to_hash(s):
    n = len(s)
    h = [0 for _ in range(n)]
    p = [0 for _ in range(n)]
    h[0] = ord(s[0])-48
    p[0] = 1
    for i in range(1,n):
        p[i] = (p[i-1]*base)%mod
        h[i] = (h[i-1] + (ord(s[i]) - 48)*p[i])%mod
    return h, p

def equal_substr(h1, h2, p, a, b, m):
    if m==0: return True
        
    ha = h1[a+m-1]
    if a > 0:
        ha -= h1[a-1]
    if ha < 0:
        ha += mod
        
    hb = h2[b+m-1]
    if b > 0:
        hb  -= h2[b-1]
    if hb < 0:
        hb += mod
    
    if a < b:
        ha *= p[b-a]
        ha %= mod
    else:
        hb *= p[a-b]
        hb %= mod
    return ha==hb
    
def solve(s):
    n = len(s)
    
    r = s[::-1]
    h1, p = string_to_hash(s)
    h2, p = string_to_hash(r)

    m = 0
    for k in range(1,n+1):
        if equal_substr(h1, h2, p, k, 0, n-k) and equal_substr(h1, h2, p, 0, n-k, k):
            m = n-k 
            break
    return r[m:]
