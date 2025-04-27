'''计算区间：对于每一对相邻的岛屿，计算其对应的桥长度的最小值和最大值，即 [min_a, max_a]。

排序：将所有桥的长度排序，同时将这些区间按照 max_a 排序（或按照某种顺序以便于匹配）。

匹配：使用贪心的方法，为每个区间选择一个最小的可用的桥长度，这样可以最大化后续的匹配可能性。'''
import sys
inputs = sys.stdin.read().split()
idx = 0
while idx < len(inputs):
    num_island,num_bridge = map(int,inputs[idx:idx+2])
    idx += 2
    islands=[]
    bridges_length=[]
    dic_bridge={}
    dic_island={}
    result=[]
    tempt=[]
    for _ in range(num_island):
        a,b=map(int,inputs[idx:idx+2])
        idx += 2
        tempt.append((a,b))
        
    for i in range(num_island-1):
        min_a=tempt[i+1][0]-tempt[i][1]
        max_a=tempt[i+1][1]-tempt[i][0]
        islands.append((i,min_a,max_a))
    
    for j in range(1,num_bridge+1):
        c=int(inputs[idx])
        idx += 1
        bridges_length.append((j,c))
        
    islands.sort(key=lambda x: x[2])
    bridges_length.sort(key=lambda x: x[1])
    for bridge in bridges_length:
        dic_bridge[bridge]=True
    for island in islands:
        dic_island[island]=False
        
    
    for island in islands:
        for bridge in bridges_length:
            if bridge[1]>=island[1] and bridge[1]<=island[2] and dic_bridge[bridge]:
                dic_bridge[bridge]=False
                result.append((island[0],bridge[0]))
                dic_island[island]=True
                break
    
    if all(dic_island.values()):
        print("Yes\n")
        result.sort(key=lambda x: x[0]) 
        for x, y in result:
            print(y, end=' ')
        
    else:
        print("No\n")

     
        
  