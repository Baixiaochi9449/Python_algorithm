#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int main(){
    int n,m;  //n行m列
    cin >> n >>m;
    vector<vector<char>> graph(n,vector<char>(m));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> graph[i][j];
        }
    }
    //广度优先搜索
    int res=0;
    vector<vector<bool>> visit(n,vector<bool>(m)); //表示已经点燃了的船
    queue<pair<int,int>> que;
    for(int i=n-1;i>=0;i--){
        for(int j=m-1;j>=0;j--){
            if(!visit[i][j] && graph[i][j]=='x'){ //没有被点燃，且有船
                res++;//点燃一下
                //递归，把所有相邻的都点燃
                visit[i][j]=true;
                que.push({i,j});
                while(!que.empty()){
                    auto cur=que.front();
                    que.pop();
                    int x=cur.first;
                    int y=cur.second;
                    
                    if(x-1>=0 && y-1>=0 && !visit[x-1][y-1] && graph[x-1][y-1]=='x'){
                        visit[x-1][y-1]=true;
                        que.push({x-1,y-1});
                    }
                    if(x-1>=0 && !visit[x-1][y] && graph[x-1][y]=='x'){
                        visit[x-1][y]=true;
                        que.push({x-1,y});
                    }
                    if(y-1>=0 && !visit[x][y-1] && graph[x][y-1]=='x'){
                        visit[x][y-1]=true;
                        que.push({x,y-1});
                    }
                }
            }
        }
    }
    cout << res << endl;
}