//搜索有几个father[i]=i 就是几个团伙
//设置当前头目， 每次更新当前头目。  给每个名字编号--为了能用father  
//读入的时候，读入一个新名字，就添加到map中。 同时设置一个vector<int> 存储的是每个人的通话时间。
//现在已经有的数据 map{AAA:0}  vector<int> [30, 40,50。。。]   father[100 ,200,300....] 这个是团队编号，可以把第一个出现的人的编号当做团队编号
//首先判断团伙，遍历father,把出现的数字存储到map中 {2：[2,100]，4：[3,40]} ，只处理次数>2的，取出团队编号n，遍历father[i]=n的 i, i为团队成员编号，同时统计数量count, 遍历vector<int> 比较大小，找出最大的通话数量的（2个temp）编号，找到对应的AAA，输出AAA和count

//读入数据的时候。 map1<AAA:1,BBB:2>  vector<int>{10,20} , father[1]=100 father[2]=100  把100放入set中
//定义一个map{团队编号：{人数，总时长}}
//join的时候，查看双方的father时候在set中，把在set中的100赋给没有在set中的，如果都没有在set中，就最后一个set++的值赋给他们，并加入set。  
#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>

using namespace std;
int MAX=100;
vector<int> father(2000);
unordered_set<int> team_id;
int beginid=1000;


void init(){
    for(int i=0;i<MAX;i++){
        father[i]=i;
    }
}

int join(int x,int y){
    //两个人的编号一样，直接跳过
    //两个人的编号不一样。 存在一个人的编号已经在set中了，给另一个人的编号添加这个标号
                        //两人编号都不在set中， 最后一个编号++ ，赋值给两个人
    int newpeople=0;
    if(father[x]==father[y]) return 0 ;
    else{
        if(team_id.empty()){
            father[x]=beginid;
            father[y]=beginid;
            team_id.insert(beginid);
            beginid++;
        }
        else{
            if(team_id.count(father[x]) && !team_id.count(father[y])){
                father[y]=father[x];
            }
            else if(team_id.count(father[y]) && !team_id.count(father[x])) {
                father[x]=father[y];
            }
            else if(team_id.count(father[x]) && team_id.count(father[y])){
                int id_1=father[x];
                int id_2=father[y];
                for(int i=0;i<MAX;i++){
                    if(father[i]==id_2){ //团队成员
                        father[i]=id_1; //把id_2的团队成员都改成id_1
                        newpeople++;
                    }
                }
                team_id.erase(id_2); //删除id_2的团队编号
            }
            else{
                father[x]=beginid;
                father[y]=beginid;
                team_id.insert(beginid);
                beginid++;
            }
        }
    }
    return newpeople; //返回新加入的人的数量
}

int main(){
    int n,k;
    while(cin >> n >> k){
        init();
        team_id.clear();
        unordered_map<string,int> name;
        int name_id=0;
        vector<int> Time(MAX,0);
        vector<int> team_time(2000,0);  //索引为团队编号
        vector<int> team_people(2000,0);

        while(n--){
            string p1,p2;
            int t;
            int newpeople=0;
            cin >> p1 >> p2 >> t;
            //1、先处理name
            if(!name.count(p1)){ //不存在这个人
                name[p1]=name_id;
                name_id++;
                newpeople++;
            }
    
            if(!name.count(p2)){ //不存在这个人
                name[p2]=name_id;
                name_id++;
                newpeople++;
            }

            //2、添加每个人的time
            Time[name[p1]]+=t;
            Time[name[p2]]+=t;
            //3、给每个人添加团队编号
            newpeople+=join(name[p1],name[p2]);

            //把团队编号对应的位置vector<int> sum_time+2t
            //把团队编号对应的位置vector<int> sum_people+newpeople
            int teamid=father[name[p1]];
            team_time[teamid]+=2*t;
            team_people[teamid]+=newpeople;
        }
        //目前已有的数据： 人名单name，每个人的时间Time,每个人的团队编号father,已有的团队编号set, 每个团队的人数sum_people ，每个团队的时间sum_time
        //遍历团队编号，选出人数和时间都满足的团队编号---遍历每个人，if(father[i]==团队编号)开始处理，找出
        vector<pair<string,int>> result;
        int sum=0;
        for(unordered_set<int>::iterator it = team_id.begin(); it != team_id.end(); ++it) {
            int teamid=*it;
            if(team_people[teamid]<=2) continue;
            if(team_time[teamid]/2<=k) continue;

            sum++;//找到了符合的团队
            int max_time=0;
            int head;
            for(int i=0;i<MAX;i++){
                if(father[i]==teamid){ //团队成员
                    if(Time[i]>max_time){
                        head=i;
                        max_time=Time[i];
                    }
                }
            }
            //i对应的string是什么 name_str
            string name_str;
            for(auto pair : name){
                if(pair.second==head){
                    name_str=pair.first;
                }
            }
            result.push_back({name_str,team_people[teamid]});
        }
        
        cout << sum <<endl;
        if(sum >0){
            sort(result.begin(),result.end());
            for(auto pair: result){
                cout << pair.first << ' ' << pair.second << endl;
            }
        }

    }
}