#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int sum_1;

vector<vector<int>> direction={{1,0},{-1,0},{0,1},{0,-1}};

void dfs(vector<vector<int>>& graph,vector<vector<bool>>& visit,int x,int y){
    for(int i=0;i<4;i++){
        int nextx=x+direction[i][0];
        int nexty=y+direction[i][1];
        if(nextx<0 || nextx>=graph.size() || nexty<0 || nexty>=graph[0].size() || graph[nextx][nexty]==0 || visit[nextx][nexty]){
            continue;
        }
        sum_1++;
        visit[nextx][nexty]=true;
        dfs(graph,visit,nextx,nexty);
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
                sum_1=0;
                if(graph[i][j]==1 && visit[i][j]==false){
                    sum_1++;
                    visit[i][j]=true;
                    dfs(graph,visit,i,j);
                }
                result=max(result,sum_1);
            }
        }
        cout << result << endl;
    }
    return 0;
}