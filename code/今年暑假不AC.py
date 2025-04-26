import sys
inputs=sys.stdin.read().split()
idx=0
while idx < len(inputs):
    program=[]
    num=1
    if inputs[idx] == '0':
        break
    n=int(inputs[idx])
    idx+=1
    for i in range(n):
        a,b=map(int,inputs[idx:idx+2])
        program.append([a,b])
        idx+=2
    
    program.sort(key=lambda x: x[1])
    j=1
    i=0
    while j<n:
        if program[i][1] <=program[j][0]:
            num+=1
            i+=1
        
        j+=1
    print(num)