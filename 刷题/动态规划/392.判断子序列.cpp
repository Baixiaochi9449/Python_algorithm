//dp[i][j] 以i-1结尾的和以j-1结尾的，是否是子序列
//相等：  不相等：
class Solution {
    public:
        bool isSubsequence(string s, string t) {
            int n=s.size();
            int m=t.size();
            vector<vector<bool>> dp(n+1,vector<bool>(m+1,false));
            // for(int i=1;i<=n;i++){ //dp[i][0] t为0，   都为false
            //     dp[]
            // }
            for(int j=0;j<=m;j++){  //dp[0][j] s为0，都为true 
                dp[0][j]=true;
            }
            for(int i=1;i<=n;i++){
                for(int j=1;j<=m;j++){
                    if(s[i-1]==t[j-1]) dp[i][j]=dp[i-1][j-1];
                    else{
                        dp[i][j]=dp[i][j-1];
                    }
                }
            }
            return dp[n][m];
        }
    };