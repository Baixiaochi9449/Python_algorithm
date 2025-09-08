#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int n,m;
    cin >> n >> m;
    string s,t;
    cin >> s >> t;
    vector<vector<int>> dp(n+1,vector<int>(m+1,0));  //dp[i][j] 以前i个 前j个的最长公共子序列的长度  dp[0][j]=0 dp[i][0]=0 
    // for(int i=0;i<=n;i++){
    //     dp[i][0]=0;
    // }
    // for(int j=0;j<=m;j++){
    //     dp[0][j]=0;
    // }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(s[i-1]==t[j-1]) dp[i][j]=dp[i-1][j-1]+1;
            else{
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
    cout <<  dp[n][m] << endl;;
    return 0;
}