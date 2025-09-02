class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        //初始选择一个位置（第一行），之后每次有3种选择 
        //dp[i][j] 走到i，j这个位置时候的最小值 dp[i][j]=min(,,) //三个值的最小值嘛
        int n=matrix.size();
        int m=matrix[0].size();
        vector<vector<int>> dp(n,vector<int>(m,0));
        for(int j=0;j<m;j++){
            dp[0][j]=matrix[0][j];
        }
        for(int i=1;i<n;i++){
            for(int j=0;j<m;j++){
                if(j-1>=0 && j+1<m){
                    int temp=min(dp[i-1][j],dp[i-1][j-1]);
                    temp=min(temp,dp[i-1][j+1]);
                    dp[i][j]=temp+matrix[i][j];
                }
                else if(j-1>=0 && j+1>=m){
                    int temp=min(dp[i-1][j],dp[i-1][j-1]);
                    dp[i][j]=temp+matrix[i][j];
                }
                else if(j-1<0 && j+1<m){
                    int temp=min(dp[i-1][j],dp[i-1][j+1]);
                    dp[i][j]=temp+matrix[i][j];
                }
                else dp[i][j]=dp[i-1][j]+matrix[i][j];
            }
        }
        int res=dp[n-1][0];
        for(int j=1;j<m;j++){
            res=min(dp[n-1][j],res);
        }
        return res;
    }
};
