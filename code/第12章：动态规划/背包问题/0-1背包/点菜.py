import sys
lines = sys.stdin.read().splitlines()
idx = 0
while idx<len(lines):
    C, N = map(int, lines[idx].split())
    idx += 1
    dishes = []
    for _ in range(N):
        price, value = map(int, lines[idx].split())
        dishes.append((price, value))
        idx += 1

    dp=[0]*(C+1)
    for price,value in dishes:
        for j in range(C,price-1,-1): #倒序处理，从最多的钱，到当前的price+1  这里的倒序是<=C    >price-1   所以包含了price
            dp[j]=max(dp[j],dp[j-price]+value)     #这个dp[j]在每个dishes这里是一直在更新的，永远保存最大的value
    
    print(dp[C])
