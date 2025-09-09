//回溯，找不同的路径，取一个最大值，到达00的时候收集结果
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int INF =1e9;
int res=INF;
int path=0;
// vector<int> collect;
void backtracking(vector<vector<char>>& graph,int x,int y,bool left){
    if(x==0 && y==0){  //走到终点时，收集结果
        res=min(res,path);
        // collect.push_back(path);
        return ;
    }
    //当前位置x,y ，每个位置2个选择
    //如果左边可以走
    if(y-1>=0 && graph[x][y-1]!='x'){//下一个要往左边走
        if(left){ //原本就是左
            backtracking(graph,x,y-1,true);
        }
        else{//当前位置是从下边来的  //现在的方向面向上
            path++;
            backtracking(graph,x,y-1,true);
            path--;
        }
    }
    //上面可以走
    if(x-1>=0 && graph[x-1][y]!='x'){
        if(left){ //原本是右边来的
            path++;
            backtracking(graph,x-1,y,false);
            path--;
        }
        else{
            backtracking(graph,x-1,y,false);
        }
    }
    return ;
}

int main(){
    int n,m;
    cin >> n >> m;
    vector<vector<char>> graph(n,vector<char>(m));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> graph[i][j];
        }
    }
    
    backtracking(graph,n-1,m-1,true);
    
    cout << res << endl;
    // for(int i=0;i<collect.size();i++){
    //     cout << collect[i] << ' ';
    // }
    return 0;
    
}
