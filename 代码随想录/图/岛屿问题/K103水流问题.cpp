//从上左开始，把大于当前数字的值 的first[][]=true
//从右下开始，把大于当前数字的值 的second[][]=true;
//最后把两个都是true的坐标输出
//代码思路：dfs()  graph 

#include <iostream>
#include <vector>

using namespace std;


vector<vector<int>> dir={{-1,0},{1,0},{0,1},{0,-1}};
void dfs(vector<vector<int>>& graph,vector<vector<bool>>& visit,int x,int y){
    if(visit[x][y]==true) return ;  //确保每个节点只被访问过一次
    visit[x][y]=true;
    for(int i=0;i<4;i++){
        int nextx=x+dir[i][0];
        int nexty=y+dir[i][1];
        if(nextx<0 || nexty<0 || nextx>=graph.size() || nexty>=graph[0].size() || visit[nextx][nexty]){
            continue;
        }
        if(graph[x][y]>graph[nextx][nexty]){
            continue;
        }
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

        vector<vector<bool>> first(n,vector<bool>(m,false));
        vector<vector<bool>> second(n,vector<bool>(m,false));

        for(int i=0;i<n;i++){
            
                dfs(graph,first,i,0);
            
            
                dfs(graph,second,i,m-1);
            
        }
        for(int j=0;j<m;j++){
            
                dfs(graph,second,0,j);
            
           
                dfs(graph,second,n-1,j);
            
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(first[i][j]==true && second[i][j]==true){
                    cout << i <<' ' << j <<endl;
                }
            }
        }
    }
    return 0;
}