import sys
line = sys.stdin.readline()
T=int(line.strip())
for _ in range(T):
    line=sys.stdin.readline()
    E,F=map(int,line.split())
    line=sys.stdin.readline()
    N=int(line.strip())
    coin=[]
    for _ in range(N):
        line=sys.stdin.readline()
        value,weight=map(int,line.split())
        coin.append((value,weight))
    
    sum_w=F-E
    dp=[float('inf')]*(sum_w+1)
    dp[0]=0
    for value,weight in coin:
        for i in range(weight,sum_w+1):
            dp[i]=min(dp[i],dp[i-weight]+value)
    
    if dp[sum_w]==float('inf'):
        print("This is impossible.")
    else:
        print(f"The minimum amount of money in the piggy-bank is {dp[sum_w]}")
            
        