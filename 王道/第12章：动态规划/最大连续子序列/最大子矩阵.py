import sys
inputs=sys.stdin.read().split()
idx=0

def max_subsequence(A:list[int]):
    dp=[0]*len(A)
    dp[0]=A[0]
    for i in range(1,len(A)):
        dp[i]=max(A[i],dp[i-1]+A[i])
    
    return max(dp)
    
    
while idx<len(inputs):
    N=int(inputs[idx])
    idx+=1
    matrix=[]
    for _ in range(N):
        row_list=[]
        for _ in range(N):
            a=int(inputs[idx])
            idx+=1
            row_list.append(a)
        matrix.append(row_list)
        
    #此处可以用到一个动态规划
    dp = [[0] * N for _ in range(N+1)]
    for j in range(0,N):
        for i in range(1,N+1):  #添加了最上面的一行0，为了计算 整个矩阵的和
            dp[i][j]=dp[i-1][j]+matrix[i-1][j]
    
    if N==1:
        print(max_subsequence(matrix[0]))
    else:
        max_num=matrix[0][0]
        for top in range(0,N):
            for bottom in range(top+1,N+1):
                sum_subsequence=[dp[bottom][k]-dp[top][k] for k in range(N)]
                current_max = max_subsequence(sum_subsequence)
                if current_max > max_num:
                    max_num = current_max
        print(max_num)
    