import sys

input = sys.stdin.read().split()
idx = 0

while idx < len(input) and input[idx] != '-1':
    catfood_M = int(input[idx])
    idx += 1
    room_N = int(input[idx])
    idx += 1
    
    seed_J = []
    catfood_F = []
    Cost_effectiveness = []
    
    for _ in range(room_N):
        j = int(input[idx])
        f = int(input[idx+1])
        seed_J.append(j)
        catfood_F.append(f)
        Cost_effectiveness.append(j / f if f != 0 else float('inf'))  # 处理除零
        idx += 2
    
    sorted_with_index = sorted(enumerate(Cost_effectiveness), key=lambda x: x[1], reverse=True)
    sorted_index = [index for index, value in sorted_with_index]
    
    leftfood = catfood_M
    get_seed = 0
    i = 0
    
    while i < len(sorted_index):
        if leftfood - catfood_F[sorted_index[i]] < 0:
            break
        leftfood -= catfood_F[sorted_index[i]]
        get_seed += seed_J[sorted_index[i]]
        i += 1
    
    if i < len(sorted_index) and leftfood > 0:
        get_seed += leftfood * Cost_effectiveness[sorted_index[i]]
    
    print(get_seed)