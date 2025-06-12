#最大的减去最小的
import sys
input = sys.stdin.read().split()
idx=0
T=int(input[idx])
idx+=1
for _ in range(T):
    num_gun,num_moster=map(int,input[idx:idx+2])
    idx+=2
    gun_list=list(map(int,input[idx:idx+num_gun]))
    idx+=num_gun
    moster_list=list(map(int,input[idx:idx+num_moster]))
    idx+=num_moster
    
    gun_list.sort(reverse=True)
    moster_list.sort()
    money=0
    for i in range(0,min(num_gun,num_moster)):
        if gun_list[i]>=moster_list[i]:
            money+=gun_list[i]-moster_list[i]
        i+=1
    print(money,"\n")
            
    