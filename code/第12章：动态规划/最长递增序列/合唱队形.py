import sys
inputs=sys.stdin.read().split()
idx=0

def increase_quence(S):
    dp=[]
    dp.append(1)
    for i in range(1,N):
        max_temp=1
        for j in range(0,i):
            if S[j]<S[i]:
                temp=max(dp[j]+1,1)
                if temp>max_temp:
                    max_temp=temp
        dp.append(max_temp)

    return dp


while idx<len(inputs):
    N=int(inputs[idx])
    idx+=1
    S=[]
    for _ in range(N):
        a=int(inputs[idx])
        idx+=1
        S.append(a)

    dp1=increase_quence(S)
    dp2=increase_quence(S[::-1])
    dp3=[]
    for i in range(N):
        sum=dp1[i]+dp2[N-1-i]-1
        dp3.append(sum)
    out_people=N-max(dp3)
    print(out_people)

    
