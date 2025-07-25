class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>> dp(n,vector<int>(4,0));
        dp[0][0]=-prices[0]; //保持股票的状态
        dp[0][1]=0; //保持着 卖出股票的状态
        dp[0][2]=0; //卖出股票的这个操作
        dp[0][3]=0; //冷冻期的状态
        for(int i=1;i<n;i++){
            dp[i][0]=max(dp[i-1][0],dp[i-1][3]-prices[i]);
            dp[i][0]=max(dp[i][0],dp[i-1][1]-prices[i]);  //3个中的最大值

            dp[i][1]=max(dp[i-1][1],dp[i-1][3]); //一直保持着， 和冷冻期后一直没买
            dp[i][2]=dp[i-1][0]+prices[i];
            dp[i][3]=dp[i-1][2];
        }
        int result = max(dp[n-1][1],dp[n-1][2]);
        result = max(result,dp[n-1][3]);
        return result;
    }
};