//完全背包。 dp[i] 凑成i的最少的硬币个数 min()  求组合数，所以先物品，再背包。
//dp[0]=0  dp[1]=
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount+1,1000000);
        dp[0]=0;
        
        for(int i=0;i<coins.size();i++){
            for(int j=coins[i];j<=amount;j++){
                dp[j]=min(dp[j],dp[j-coins[i]]+1);
            }
        }
        if(dp[amount]==1000000) return -1;
        return dp[amount];
    }
};