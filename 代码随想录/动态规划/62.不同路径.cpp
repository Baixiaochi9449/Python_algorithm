//图的题，如果要保存具体的路径，----图的深搜或广搜； 如果只是问最后有多少种----动态规划
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m,vector<int>(n,0));
        //dp的含义，到达 i,j位置有多少条不同的路径
        for(int j=0;j<n;j++){
            dp[0][j]=1;
        }
        for(int i=0;i<m;i++){
            dp[i][0]=1;
        }
        //递推公式：dp[i][j]=dp[i][j-1]+dp[i-1][j]
        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                dp[i][j]=dp[i][j-1]+dp[i-1][j];
            }
        }
        return dp[m-1][n-1];
        
    }
};