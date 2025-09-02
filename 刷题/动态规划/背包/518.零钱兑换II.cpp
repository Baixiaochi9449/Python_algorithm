class Solution {
public:
    int change(int amount, vector<int>& coins) {
        //完全背包的 装满这个背包有多少种方法 都是dp[j]+=dp[j-nums[i]]
        //求组合数 先遍历物品
        int n=coins.size();
        vector<uint64_t> dp(amount+1,0);
        dp[0]=1;
        for(int i=0;i<n;i++){
            for(int j=coins[i];j<=amount;j++){
                dp[j]+=dp[j-coins[i]];
            }
        }
        return dp[amount];
    }
};
