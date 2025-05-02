#一次性全部读入会占用很大内存
# import sys
# inputs=sys.stdin.read().split()
# idx=0
# while idx<len(inputs):
#     N=int(inputs[idx])
#     idx+=1
#     S=[]
#     for _ in range(N):
#         a=int(inputs[idx])
#         idx+=1
#         S.append(a) 

#     dp=[0]*N
#     dp[0]=S[0]
#     for i in range(1,N):
#         dp[i]=S[i]
#         for j in range(0,i):
#             if S[j]<S[i]:
#                 dp[i]=max(S[i],dp[j]+S[i])
#     print(max(dp))

# import sys

#采用逐行读入
import sys
def solve():
    for line in sys.stdin:
        N = int(line.strip())
        S = list(map(int, sys.stdin.readline().strip().split()))
        
        dp = [0] * N
        dp[0] = S[0]
        for i in range(1, N):
            dp[i] = S[i]
            for j in range(i):
                if S[j] < S[i]:
                    dp[i] = max(dp[i], dp[j] + S[i])
        print(max(dp))

solve()