#include <iostream>
#include <vector>
#include <list>

using namespace std;

vector<int> path;
vector<vector<int>> result;

void dfs(vector<list<int>>& graph ,int x,int n){
    if(x==n){
        result.push_back(path);
        return ;
    }
    for(int i :graph[x]){   //用邻接表直接遍历它邻接的节点，遍历x连接的所有节点
        path.push_back(i);
        dfs(graph,i,n);
        path.pop_back();
    }
}

int main(){
    int n,m;
    while(cin >> n>> m){
        vector<list<int>> graph(n+1);
        while(m--){
            int i,j;
            cin >> i >> j;
            graph[i].push_back(j);
        }

        path.clear();
        result.clear();
        path.push_back(1);
        dfs(graph,1,n);
        for(auto r :result){
            for(int i=0;i<r.size()-1;i++){
                cout << r[i] << ' ';
            }
            cout << r[r.size()-1] << endl;
        }
    }
    return 0;
}