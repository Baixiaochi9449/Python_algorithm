#最大子序列的和   子序列的第一个元素   子序列的第二个元素
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
    
    if N==1:
        b=max(S)
        print(b,b,b)
    else:
        dp=[]
        dp.append([S[0],S[0],S[0]])
        temp=[]
        for i in range(1,N):
            if S[i]>S[i]+dp[i-1][0]:
                temp=S[i]
                dp.append([temp,S[i],S[i]])
            else:
                temp=S[i]+dp[i-1][0]
                dp.append([temp,dp[i-1][1],S[i]])
        
        max_subarray = max(dp, key=lambda x: x[0])
        print(max_subarray[0],max_subarray[1],max_subarray[2])
            
