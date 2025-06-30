#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> direction={{1,0},{-1,0},{0,1},{0,-1}};

void dfs(vector<vector<int>>& graph,int x,int y){
    for(int i=0;i<4;i++){
        int nextx=x+direction[i][0];
        int nexty=y+direction[i][1];
        if(nextx<0 || nextx>=graph.size() || nexty<0 || nexty>=graph[0].size()  || graph[nextx][nexty]==0){
                continue;
            }
        graph[nextx][nexty]=0;
        
        dfs(graph,nextx,nexty);
        //不需要回溯
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
        
        for(int i=0;i<n;i++){
            if(graph[i][0]==1 ){
                graph[i][0]=0;
               
                dfs(graph,i,0);
            }
            if(graph[i][m-1]==1 ){
                graph[i][m-1]=0;
                
                dfs(graph,i,m-1);
            }
        }
        for(int j=0;j<m;j++){
            if(graph[0][j]==1){
                graph[0][j]=0;
                
                dfs(graph,0,j);
            }
            if(graph[n-1][j]==1){
                graph[n-1][j]=0;
               
                dfs(graph,n-1,j);
            }
        }
        int count=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                count+=graph[i][j];
            }
        }
        cout << count << endl;
    }
}