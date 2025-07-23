//最短路径，DJ
//minDIst,找到距离源点最近的点
//标记为已经访问
//更新minDist
//想起来了2个优化，首先把图保存到邻接表中
//第二个优化是为了不每次都找最小值，所以用了一个 优先级队列
#include <iostream>
#include <vector>
#include <list>
#include <queue>

using namespace std;

class mycomparison {
public:
    bool operator()(const pair<int, int>& lhs, const pair<int, int>& rhs) {
        return lhs.second > rhs.second;
    }
};
int main(){
    int n,m;
    while(cin >> n >>m){
        vector<list<pair<int,int>>> graph(n+1); //从1开始的
        for(int i=0;i<m;i++){
            int s,t,val;
            cin >> s >> t >> val;
            graph[s].push_back({t,val});
        }
        vector<int> minDIst(n+1,10000);
        vector<bool> visit(n+1,false);
        int start=1;
        int end=n;
        minDIst[start]=0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, mycomparison> que;

        que.push({1,0});  
        while(!que.empty()){
            auto cur=que.top();  //找到了最小的点
            que.pop();
            if(visit[cur.first]) continue;
            visit[cur.first]=true;  //仅从队列取出时才标记为已访问

            for(auto edge:graph[cur.first]){
                if(!visit[edge.first] && (cur.second+edge.second)<minDIst[edge.first]){
                    minDIst[edge.first]=cur.second+edge.second;
                    que.push({edge.first,minDIst[edge.first]});
                
                }
            }
        }
        if(minDIst[end]==10000) cout << -1 << endl;
        else cout << minDIst[end] << endl;

    }

}