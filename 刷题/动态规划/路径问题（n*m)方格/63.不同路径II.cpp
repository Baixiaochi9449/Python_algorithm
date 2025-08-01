//dp[i][j] 从0，0 走到i,j 的路径的数量
//从左边和上边推导出来。 dp[i][j]=dp[i-1][j]+dp[i][j-1] 
//初始化： 第一行=1  第一列=1
class Solution {
    public:
        int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
            int n=obstacleGrid.size();
            int m=obstacleGrid[0].size();
    
            vector<vector<int>> dp(n,vector<int>(m,0)); //初始全为0
            for(int i=0;i<n;i++){ //n行，第一列
                if(obstacleGrid[i][0]!=1) dp[i][0]=1;
                else  break;
            }
            for(int j=0;j<m;j++){ //m列，第一行
                if(obstacleGrid[0][j]!=1) dp[0][j]=1;
                else break;
            }
            for(int i=1;i<n;i++){
                for(int j=1;j<m;j++){
                    if(obstacleGrid[i][j]!=1)  dp[i][j]=dp[i-1][j]+dp[i][j-1];
                }
            }
            return dp[n-1][m-1];
        }
    };