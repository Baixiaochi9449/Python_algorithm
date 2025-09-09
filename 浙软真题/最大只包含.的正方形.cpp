//最大正方形,使正方形内部都是.  
//n,m
//暴力怎么做：从大到小枚举正方形的边长,max_len=min(n,m);判断从0，0开始的左上角是否有满足的情况，移动正方形

//天啊，这个暴力复杂地写都不想写
//动态规划，边长。 从上往下，从左往右，判断以i,j为右下角的正方形的最大边长，等于上边，左边，左上的 三个的最小边长
//初始值全为0，如果三者中有一个是x，那么dp[i][j]=1;  x的位置为0，（直接跳过）
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int n,m;
    cin >> n >> m;
    vector<vector<char>> graph(n,vector<char>(m));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> graph[i][j];
        }
    }
    vector<vector<int>> dp(n,vector<int>(m,0));
    for(int i=0;i<n;i++){ //第一列
        if(graph[i][0]!='x') dp[i][0]=1;
    }
    for(int j=0;j<m;j++){
        if(graph[0][j]!='x') dp[0][j]=1;
    }
    int lenth=0;
    for(int i=1;i<n;i++){
        for(int j=1;j<m;j++){
            if(graph[i][j]=='x') continue;
            dp[i][j]=min(dp[i-1][j],min(dp[i][j-1],dp[i-1][j-1]))+1;
            lenth=max(dp[i][j],lenth);
        }
    }
    cout << lenth*lenth << endl;
    
}