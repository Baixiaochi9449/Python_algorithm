//用string来表示状态，每次状态转移是 把x的上下左右的数移动到x的位置上
#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>
using namespace std;

int main(){
    string start;
    for(int i=0;i<9;i++){
        char c;
        cin >> c;
        start+=c;
    }
    vector<vector<int>> dir={{1,0},{-1,0},{0,1},{0,-1}};
    string end="12345678x";
    queue<string> que;
    unordered_map<string,int> dis;
    //初始化
    dis[start]=0;
    que.push(start);
    while(!que.empty()){
        string str=que.front();
        que.pop();
        //要在一开始就判断是否已经到达终点
        if(str==end) {
            cout << dis[str] << endl;
            return 0;
        }
        //开始进行状态转移
        int k=str.find('x');
        int x=k/3,y=k%3;
        int distance=dis[str];
        for(int i=0;i<4;i++){
            int nx=x+dir[i][0];
            int ny=y+dir[i][1];
            if(nx<0 || nx>=3 || ny<0 || ny>=3) continue;
            swap(str[k],str[nx*3+ny]);
            if(dis.find(str)==dis.end()){
                dis[str]=distance+1;
                que.push(str);
            }
            swap(str[k],str[nx*3+ny]);
        }
    }
    cout << -1<< endl;
    return 0;
}
