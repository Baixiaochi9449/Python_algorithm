//广度优先搜索
//谁先到达目标值，谁就是最少的？ 没错BFS本身就能找到最短路径
#include <iostream>
#include <vector>
#include <queue>
using namespace std;


int main(){
    vector<vector<int>> dir = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    int n, m;
    cin >> n >> m;
    vector<vector<int>> graph(n, vector<int>(m));
    vector<vector<bool>> visit(n, vector<bool>(m, false));
    vector<vector<int>> distance(n, vector<int>(m, -1)); // 初始化为-1表示未访问

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> graph[i][j];
        }
    }
    queue<pair<int,int>> que;
    que.push({0,0});
    distance[0][0]=0;
    visit[0][0]=true;
    
    while(!que.empty()){
        auto pair=que.front();
        que.pop();
        int x=pair.first;
        int y=pair.second;
        if(x==n-1 && y==m-1){
            cout << distance[x][y] << endl;
            return 0;
        }
        for(int i=0;i<4;i++){
            int nextx=x+dir[i][0];
            int nexty=y+dir[i][1];
            if(nextx<0 || nexty<0 || nexty>=m || nextx>=n || visit[nextx][nexty]) continue;
            if(graph[nextx][nexty]==1) continue;
            
            distance[nextx][nexty]=distance[x][y]+1;
            que.push({nextx,nexty});
            visit[nextx][nexty]=true;
        }
    }
    
    return 0;
}
