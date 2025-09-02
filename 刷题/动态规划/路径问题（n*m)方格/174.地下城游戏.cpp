//思路错误！！！ 如果从半路死了，之后有再多的生命也不行了
//这道题要从后往前推，设定dp[n-1][m-1]=0   dp[i][j]  从i,j走到终点需要的最小的健康值
class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int n=dungeon.size();
        int m=dungeon[0].size();
        vector<vector<int>> dp(n,vector<int>(m));
        dp[n-1][m-1]=max(1,1-dungeon[n-1][m-1]);   //初始安全值最少为1， 
        for(int j=m-2;j>=0;j--){
            dp[n-1][j]=max(1,dp[n-1][j+1]-dungeon[n-1][j]);
        }
        for(int i=n-2;i>=0;i--){
            dp[i][m-1]=max(1,dp[i+1][m-1]-dungeon[i][m-1]);
        }
        for(int i=n-2;i>=0;i--){
            for(int j=m-2;j>=0;j--){
                int min_need=min(dp[i+1][j],dp[i][j+1]);
                dp[i][j]=max(1,min_need-dungeon[i][j]);
            }
        }
        return dp[0][0];
    }
};
