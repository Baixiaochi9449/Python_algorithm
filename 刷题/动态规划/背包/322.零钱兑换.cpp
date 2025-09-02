class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        //完全背包，先遍历物品，再正序遍历背包
        //dp[i] 装满容量为i的背包，最少需要的硬币个数  dp[0]=0  dp[1]=
        //dp[i]=min(dp[i],dp[i-val]+1);
        int n=coins.size();
        vector<int> dp(amount+1,1000000);
        dp[0]=0;
        for(int i=0;i<n;i++){
            for(int j=coins[i];j<=amount;j++){
                dp[j]=min(dp[j],dp[j-coins[i]]+1);
            }
        }
        if(dp[amount]==1000000) return -1;
        return dp[amount];
    }
};
