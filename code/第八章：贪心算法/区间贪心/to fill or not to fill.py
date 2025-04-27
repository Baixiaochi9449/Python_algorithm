import sys
inputs = sys.stdin.read().split()
idx = 0
while idx < len(inputs):
    station=[]
    Cmax,distence_toD,Davg,num_station= map(int,inputs[idx:idx+4])
    idx += 4
    for _ in range(num_station):
        price,dis=map(int,inputs[idx:idx+2])
        station.append((price,dis))
        idx += 2
    station.sort(key=lambda x: x[1])
    
    if all(sta[1]!=0 for sta in station):
        print("-1")   
    else:
        current_price=station[0][0]
        count=0
        max_distence=Cmax*Davg
        for j in range(num_station):
            count=j
            for i in range(j,num_station):
                #找到一个价格比当前价格少的---如果加满油够距离，就走；加满油不够距离，（1，i)之间按照价格排序，从第一个开始比较距离够不够，够就直接走
                if station[i+1][0]<current_price:
                    distence=station[i+1][1]-station[i][1]
                    if max_distence>=distence:
                        need_fill=distence//Davg
                        price+=need_fill*station[i][0]
                        current_price=station[i+1][0]
                        count+=(i+1)
                        break
            if count!=j:
                j=count
                
            else:
                price_list=sorted(station[1:j],key=lambda x: x[0])
                for item in price_list:
                    if max_distence>=item[j+1][1]-item[j][1]:
                        need_fill=max_distence//Davg
                        price+=need_fill*current_price
                        current_price=item[j+1][0]
                        break
                    
                
            
                    
            
                
        
                
                   
            
                