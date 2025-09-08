//dp[i][j] 走到i,j这个位置时候的最大路径
//dp[i][j]=max(dp[i-1][j],dp[i-1][j-1])+graph[i][j];
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<vector<int>> graph(n,vector<int>(n));
    for(int i=0;i<n;i++){
        for(int j=0;j<i+1;j++){
            cin >> graph[i][j];
        }
    }
    vector<vector<int>> dp(n,vector<int>(n));
    dp[0][0]=graph[0][0];
    for(int i=1;i<n;i++){
        for(int j=0;j<i+1;j++){
            if(j==0) dp[i][j]=dp[i-1][j]+graph[i][j];
            else if(j==i) dp[i][j]=dp[i-1][j-1]+graph[i][j];
            else dp[i][j]=max(dp[i-1][j],dp[i-1][j-1])+graph[i][j];  //没有处理边界情况：j=0时，只能从上方来，j=i时候，只能从左上方来
        }
    }
    int res=dp[n-1][0];
    for(int j=1;j<n;j++){
        res=max(res,dp[n-1][j]);
    }
    cout << res << endl;
    return 0;
}