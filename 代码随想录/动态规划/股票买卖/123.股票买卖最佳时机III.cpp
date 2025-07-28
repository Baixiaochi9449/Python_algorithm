//定义5个值 
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>> dp(n,vector<int>(5,0));
        dp[0][0]=0;  //什么状态
        dp[0][1]=-prices[0]; //第一次买入
        dp[0][2]=0;  //第一次卖出
        dp[0][3]=-prices[0];  //第二次买入
        dp[0][4]=0;   //第二次卖出

        for(int i=1;i<n;i++){
            dp[i][0]=dp[i-1][0];
            dp[i][1]=max(dp[i-1][1],dp[i][0]-prices[i]);
            dp[i][2]=max(dp[i-1][2],dp[i][1]+prices[i]);
            dp[i][3]=max(dp[i-1][3],dp[i-1][2]-prices[i]);
            dp[i][4]=max(dp[i-1][4],dp[i-1][3]+prices[i]);
        }
        return dp[n-1][4];
    }
};