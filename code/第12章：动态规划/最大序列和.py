#最长子序列的算法关键：存储结尾为i的最长子序列的长度， dp[i]=max(S[i], dp[i-1]+S[i]) 
#dp[i]要么是当前值，要么是当前值+前面的值   所以dp[i-1]+S[i]肯定是连起来的
# 如果当前值加上前面的值大于当前值，说明当前值可以和前面的值组成一个更大的子序列
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
    dp[0]=S[0]
    for i in range(1,N):
        dp[i]=max(S[i],(dp[i-1]+S[i]))
    print(max(dp))
                



