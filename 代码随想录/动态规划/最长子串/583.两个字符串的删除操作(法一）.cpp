//思路1：求最长公共子序列的长度
class Solution {
    public:
        int minDistance(string word1, string word2) {
            int n=word1.size();
            int m=word2.size();
            vector<vector<int>> dp(n+1,vector<int>(m+1,0));  //dp[i][j] 以i-1 和j-1为结尾的公共子序列的长度
            //初始化都为0
            int result=0;
            for(int i=1;i<=n;i++){
                for(int j=1;j<=m;j++){
                    if(word1[i-1]==word2[j-1]) dp[i][j]=dp[i-1][j-1]+1;
                    else dp[i][j]=max(dp[i][j-1],dp[i-1][j]);
                    result=max(result,dp[i][j]);
                }
            } 
            return n+m-2*result;
        }
    };