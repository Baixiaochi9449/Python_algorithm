import sys
inputs=sys.stdin.read().split()
idx=0
while idx<len(inputs):
    M,N=map(int,inputs[idx:idx+2])
    idx+=2
    prices=[]
    for _ in range(N):
        a=int(inputs[idx])
        idx+=1
        prices.append(a)
    
    dp=[float('inf')]*(M+1)
    dp[0]=0
    for price in prices:
        for i in range(M,price-1,-1):
            dp[i]=min(dp[i],dp[i-price]+1)
    print(dp[M] if dp[M] != float('inf') else 0)
    