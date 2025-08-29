//dp[i][j] 前i个 j个 的序列的 最长公共子序列的长度
//n+1 m+1;
//dp[0][0]=0  dp[0][j]=0  dp[j][0]=0  
//如果相等 t1[i-1]==t2[j-1]  dp[i][j]=dp[i-1][j-1]+1 
//如果不相等 dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n=text1.size();
        int m=text2.size();
        vector<vector<int>> dp(n+1,vector<int>(m+1,0));
        int res=0;
        //都初始化为0 ，就不用单独初始化了
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(text1[i-1]==text2[j-1]){
                    dp[i][j]=dp[i-1][j-1]+1;
                }
                else{
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                }
                res=max(res,dp[i][j]);
            }
        }
        return res;
    }
};
