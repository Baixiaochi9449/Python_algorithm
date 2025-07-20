//装满背包有多少种方法？
//dp[j]+=dp[j-w[i]]
class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<uint64_t> dp(amount+1,0);  //防止相加数据超int
        dp[0]=1;   //dp[0]必须是1，如果是0就全都是0了
        for(int i=0;i<coins.size();i++){
            for(int j=coins[i];j<amount+1;j++){
                dp[j]+=dp[j-coins[i]];
            }
        }
        return dp[amount];
    }
};