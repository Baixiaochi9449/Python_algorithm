import sys
inputs=sys.stdin.read().split()
idx=0
while idx<len(inputs):
    dp=[]
    dp[0]=0
    dp[1]=1
    dp[2]=2
    N=int(inputs[idx])
    idx+=1
    for i in range(2,N+1):
        dp[i]=dp[i-1]+dp[i-2]
    print(dp[N])
   