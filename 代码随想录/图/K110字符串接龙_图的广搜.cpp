//每次改一个字母，先判断是否==endstr，再判断是否为6个之一； 加入队列，直到endstr
//图的广搜，谁先搜到，谁就是最短的

#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <queue>
using namespace std;

unordered_set<string> strset;
queue<pair<string,int>> que;
unordered_set<string> visit;

int bfs(string endstr){
    while(!que.empty()){   //注意这里是while!!!! 别写成if
        auto cur=que.front();
        que.pop();
        for(int i=0;i<cur.first.size();i++){
            auto next=cur;
            for(int j=0;j<26;j++){
                char c = j+'a';
                if (c == cur.first[i]) continue;  // 跳过相同字符
                next.first[i]=c;

                if(next.first==endstr){  //最后的答案不在strset中，所以需要在前面写这个判断
                    return cur.second+1;
                }

                if(visit.find(next.first)!=visit.end()) continue;
                if(strset.find(next.first)==strset.end()) continue;

                visit.insert(next.first);
                next.second = cur.second+1;
                que.push(next);
            }
        }
    }
    return 0;
}

int main(){
    int n;
    while(cin >> n){
        string beginstr,endstr;
        cin >> beginstr >> endstr;
        while(n--){
            string s;
            cin >> s;
            strset.insert(s);
        }
        que.push({beginstr,1});
        cout << bfs(endstr) <<endl;
    }
    return 0;
}