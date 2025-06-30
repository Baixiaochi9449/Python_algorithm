//用邻接表来存储。 用深度优先搜索访问。能访问到的点，就vector=true
#include <iostream>
#include <vector>
#include <list>

using namespace std;

void dfs(vector<list<int>>& graph,vector<int>& visit,int node){
    if(visit[node]) return ;
    visit[node]=true;
    for(auto next : graph[node]){
        dfs(graph,visit,next);
    }
    return ;
}


int main(){
    int n,m;
    while(cin >> n >> m){
        vector<list<int>> graph(n+1);
        for(int i=0;i<m;i++){   //存储的是边！！！
            int a,b;
            cin >> a >> b;
            graph[a].push_back(b);
        }
        vector<int> visit(n+1,false);
        //不要for循环，遍历节点，for循环（都是在dfs内部进行的），直接从节点1开始dfs
        dfs(graph,visit,1);

        for(int i=1;i<n;i++){
            if(!visit[i]){
                cout << -1 << endl;
                return 0;
            }
        }
        cout << 1 << endl;
    }
    return 0;
}