//思路1：求最长公共子序列的长度
//思路2：按照删除来做 dp[i][j] 以i-1结尾的word1和以j-1结尾的word2 需要操作的次数
class Solution {
    public:
        int minDistance(string word1, string word2) {
            int n=word1.size();
            int m=word2.size();
            vector<vector<int>> dp(n+1,vector<int>(m+1,0));  //
            //初始化
            for(int i=0;i<=n;i++){
                dp[i][0]=i;
            }
            for(int j=0;j<=m;j++){
                dp[0][j]=j;
            }
            for(int i=1;i<=n;i++){
                for(int j=1;j<=m;j++){
                    if(word1[i-1]==word2[j-1]) dp[i][j]=dp[i-1][j-1];
                    else {
                        dp[i][j]=min(dp[i-1][j]+1,dp[i][j-1]+1);
                        dp[i][j]=min(dp[i][j],dp[i-1][j-1]+2);
                    }
                }
            }
            return dp[n][m];
        }
    };