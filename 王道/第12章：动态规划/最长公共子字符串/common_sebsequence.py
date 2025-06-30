#不是要两个同时遍历，就弄一个内循环和一个外循环，因为有可能是  s1的前两个和s2的后两个，所以不能下标同时变
#我认为是为了好动态规划，所以要设置dp[n+1][m+1] 设置dp[0][j] 和dp[i][0]为空字符串的情况
#最后就是返回dp[n][m]，可以看dp[i][j]=max(dp[i][j-1],dp[i-1][j])，如果不相等，永远都是等于前面的最大的，所以保存的永远是当前所有这个长度最大的
#不需要额外设置i=0 j=0的情况，因为循环的时候就没有从0开始，而且在最开始定义的时候，就已经是0了
import sys
inputs=sys.stdin.read().split()
idx=0
while idx<len(inputs):
    s1,s2=inputs[idx:idx+2]
    idx+=2
    n=len(s1)
    m=len(s2)
    dp=[[0]*(m+1) for _ in range(n+1)]
    for i in range(1,n+1):
        for j in range(1,m+1):
            if s1[i-1]==s2[j-1]:
                dp[i][j]=dp[i-1][j-1]+1
            else:
                dp[i][j]=max(dp[i][j-1],dp[i-1][j])
    print(dp[n][m])