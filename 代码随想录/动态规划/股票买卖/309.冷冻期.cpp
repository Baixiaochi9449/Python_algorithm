//无限次交易。因为含冷冻期，所以需要定义的状态
//dp[i][0] 持有股票的状态： 不包含对price的处理
//dp[i][1] 保持卖出的状态
//dp[i][2] 卖出的操作
//dp[i][3] 冷冻期

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>> dp(n,vector<int>(4,0));
        dp[0][0]=-prices[0];
        dp[0][1]=0;
        dp[0][2]=0;
        dp[0][3]=0;
        for(int i=1;i<n;i++){
            dp[i][0]=max(dp[i-1][0],dp[i-1][3]-prices[i]);
            dp[i][0]=max(dp[i][0],dp[i-1][1]-prices[i]);

            dp[i][1]=max(dp[i-1][1],dp[i-1][3]);  //一直处于卖出状态，前一天是冷冻期

            dp[i][2]=dp[i-1][0]+prices[i];

            dp[i][3]=dp[i-1][2];
        }
        int result = max(dp[n-1][2],dp[n-1][1]);
        result=max(result,dp[n-1][3]);
        return result;
    }
};