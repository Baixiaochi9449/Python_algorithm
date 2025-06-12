#定义字典，都出现过一次，就切换一次，注意边界问题！！！
import sys
inputs=sys.stdin.read().split()
idx=0
while idx<len(inputs):
    change_num=0
    n=int(inputs[idx])
    idx+=1
    agents={}
    for _ in range(n):
        a=str(inputs[idx])
        agents[a]=True
        idx+=1
    m=int(inputs[idx])
    idx+=1
    targets=[]
    for _ in range(m):
        targets.append(str(inputs[idx]))
        idx+=1

    if n==1:
        key=list(agents.keys())[0]
        if key  in targets:
            print(-1)
    else:
        current_agents=agents.copy()
        for target in targets:
            if target in current_agents:
                current_agents[target]=False
            if all(not agent for agent in current_agents.values()):
                change_num+=1
                current_agents=agents.copy()
                current_agents[target]=False  #最后一个出现的又意味着第一个出现
        print(change_num)


    
