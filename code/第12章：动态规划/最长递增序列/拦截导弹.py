##核心代码 ：找前面每一个比S[i]小的数，然后找到序列长度为i的时候的最长的非递增序列。dp[i]=max(dp[i],dp[j]+1)
import sys
inputs=sys.stdin.read().split()
idx=0
while idx<len(inputs):
    N=int(inputs[idx])
    idx+=1
    S=[]
    for _ in range(N):
        a=int(inputs[idx])
        idx+=1
        S.append(a)
    
    dp=[0]*N
    dp[0]=1
    for i in range(N):
        dp[i]=1     #核心代码 ：找前面每一个比S[i]小的数，然后找到序列长度为i的时候的最长的非递增序列。dp[i]=max(dp[i],dp[j]+1)
        for j in range(0,i):
            if S[j]>=S[i]:
                dp[i]=max(dp[i],dp[j]+1)

    print(max(dp))