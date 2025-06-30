#include <iostream>
#include <vector>

using namespace std;

vector<int> path;
vector<vector<int>> result;

void dfs(vector<vector<int>>& graph ,int x,int n){
    if(x==n){
        result.push_back(path);
        return ;
    }
    for(int i=1;i<=n;i++){   //遍历x连接的所有节点
        if(graph[x][i]==1){
            path.push_back(i);
            dfs(graph,i,n);
            path.pop_back();
        }
    }
}

int main(){
    int n,m;
    while(cin >> n>> m){
        vector<vector<int>> graph(n+1,vector<int>(n+1,0));
        while(m--){
            int i,j;
            cin >> i >> j;
            graph[i][j]=1;
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