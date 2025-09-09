//回溯，找不同的路径，取一个最大值，到达00的时候收集结果
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int INF=1e9;

int main(){
    int n,m;
    cin >> n >> m;
    vector<vector<char>> graph(n,vector<char>(m));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> graph[i][j];
        }
    }
    
    //如果用动态规划：dp[i][j] 从n-1,m-1走到i,j最少需要的改变方向的步数
    //一个isvalid数组 表示一个位置是否已经被走过，只有被走过，才能更新dp数组
    //初始化：dp[n-1][j]  只考虑不为x的位置
    vector<vector<int>> isvalid(n,vector<int>(m,false));
    vector<vector<int>> dp(n,vector<int>(m,INF));
    vector<vector<int>> dir(n,vector<int>(m,1)); //到达i,j这个位置面朝的方向 ,0代表超左，1代表朝上
    
    for(int j=m-1;j>=0;j--){
        if(graph[n-1][j]=='x'){
            break;
        }
        dp[n-1][j]=0;
        isvalid[n-1][j]=true;
        dir[n-1][j]=0;
    }
    for(int i=n-1;i>=0;i--){
        if(graph[i][m-1]=='x'){
            break;
        }
        dp[i][m-1]=1;
        isvalid[i][m-1]=true;
        dir[i][m-1]=1;
    }
    for(int i=n-2;i>=0;i--){
        for(int j=m-2;j>=0;j--){
            //当前坐标i,j 计算它的dp[i][j]=min(dp[i+1][j])
            if(graph[i][j]=='x') continue;
            
            if(isvalid[i+1][j]){
                if(dir[i+1][j]==0){ //原本超左，现在要往上走
                    dp[i][j]=min(dp[i][j],dp[i+1][j]+1);
                }
                else dp[i][j]=min(dp[i][j],dp[i+1][j]);
            }
            if(isvalid[i][j+1]){ //来自右边
                if(dir[i][j+1]==0){
                    if(dp[i][j]>dp[i][j+1]){
                        dp[i][j]=dp[i][j+1];
                        dir[i][j]=0;
                    }
                }
                else{
                    if(dp[i][j]>dp[i][j+1]+1){
                        dp[i][j]=dp[i][j+1]+1;
                        dir[i][j]=0;
                    }
                }
            }
            isvalid[i][j]=true;
        }
    }
    cout << dp[0][0];
    return 0;
    
}
