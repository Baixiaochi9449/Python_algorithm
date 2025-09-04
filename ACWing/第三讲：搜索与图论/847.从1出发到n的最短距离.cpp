//从1走到n的最短距离，bfs,先走到的，就是最短的
#include <iostream>
#include <vector>
#include <list>
#include <queue>
using namespace std;

vector<list<int>> graph(1e5+10);
vector<int> dist(1e5+10,-1); //初始化为-1，表示未访问
vector<bool> visit(1e5+10,false);
int n;

int main(){
    int m;
    cin >> n >> m;
    while(m--){
        int a,b;
        cin >> a >>b;
        graph[a].push_back(b);
    }

    queue<int> que;
    que.push(1);
    dist[1]=0;//从1出发目前距离为0
    visit[1]=true;
    
    while(!que.empty()){
        int node=que.front();
        que.pop();
        if(node==n){
            cout << dist[node] << endl;
            return 0;
        }
        for(auto next:graph[node]){
            if(!visit[next]){
                dist[next]=dist[node]+1;
                que.push(next);
                visit[next]=true;
            }
        }
    }
    cout << -1 << endl;
    return 0;
}
