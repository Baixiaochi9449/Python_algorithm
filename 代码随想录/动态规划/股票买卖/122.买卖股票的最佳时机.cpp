//多次买卖股票 还是只有2种状态。 持有股票dp[i][0]=max(dp[i-1][0],dp[i-1][1]-prices[i])
//不持有股票 dp[i][1]=max(dp[i-1][1],dp[i-1][0]+prices[i]);
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>> dp(n,vector<int>(2,0));
        dp[0][0]=-prices[0];
        dp[0][1]=0;
        for(int i=1;i<n;i++){  //
            dp[i][0]=max(dp[i-1][0],dp[i-1][1]-prices[i]);
            dp[i][1]=max(dp[i-1][1],dp[i-1][0]+prices[i]);
        }
        return dp[n-1][1];
    }
};