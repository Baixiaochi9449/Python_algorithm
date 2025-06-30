//对于这个二维矩阵，从第一个元素开始遍历，处理：周围四个方向，如果有陆地 就变成true,用了一个递归，把这一片所有的陆地都变成了true。 所以再接着遍历的时候，遍历到陆地都不会再result++

#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> direction={{1,0},{-1,0},{0,-1},{0,1}};
void dfs(vector<vector<int>>& graph,vector<vector<bool>>& visit,int x,int y,int n,int m){
    for(int i=0;i<4;i++){
        int nextx=x+direction[i][0];
        int nexty=y+direction[i][1];
        if(nextx>=n || nextx<0 || nexty>=m || nexty<0 ||visit[nextx][nexty] || graph[nextx][nexty]==0 ){
            continue;
        }
        visit[nextx][nexty]=true;
        dfs(graph,visit,nextx,nexty,n,m);
    }
}

int main(){
    int n,m;
    while(cin >> n >> m){
        vector<vector<int>> graph(n,vector<int>(m));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cin >> graph[i][j];
            }
        }

        vector<vector<bool>> visit(n,vector<bool>(m,false));
        int result=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(graph[i][j]==0 || visit[i][j]){
                    continue;
                }
                result++;
                dfs(graph,visit,i,j,n,m);
            }
        }
        cout << result << endl;
    }
    return 0;
}