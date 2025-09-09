//如果matrix[i][j]==1   dp[i][j] 为上，左，左上的dp最小值+1  这个dp保存的是以i,j为右下角的边长
class Solution {
    public:
        int maximalSquare(vector<vector<char>>& matrix) {
            int n=matrix.size();
            int m=matrix[0].size();
            vector<vector<int>> dp(n,vector<int>(m));
            int res=0;
            for(int i=0;i<n;i++){
                dp[i][0]=matrix[i][0]-'0';
                res=max(res,dp[i][0]);
            }
            for(int j=0;j<m;j++){
                dp[0][j]=matrix[0][j]-'0';
                res=max(res,dp[0][j]);
            }
            for(int i=1;i<n;i++){
                for(int j=1;j<m;j++){
                    if(matrix[i][j]=='0') dp[i][j]=0;
                    else{
                        dp[i][j]=min(dp[i-1][j],min(dp[i][j-1],dp[i-1][j-1]))+1;
                    }
                    res=max(res,dp[i][j]);
                }
            }
            int maxsuare=res*res;
            return maxsuare;
        }
    };