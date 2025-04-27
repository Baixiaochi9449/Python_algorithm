import sys
inputs=sys.stdin.read().split()
idx=0
while idx<len(inputs):
    N=int(inputs[idx])
    idx+=1
    dic={}
    dic[1]=1
    dic[2]=2

    for i in range(3,N+1):
        dic[i]=dic[i-1]+dic[i-2]
    
    print(dic[N],"\n")
