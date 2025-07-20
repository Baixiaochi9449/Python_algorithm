//物品是1 4 9 16...,背包容量是n .//完全背包，正序遍历背包取最小值
//如何遍历物品？ int 1=0;i*i<=n;i++
class Solution {
public:
    int numSquares(int n) {
        vector<uint64_t> dp(n+1,INT_MAX);
        dp[0]=0;
        for(int i=0;i*i<=n;i++){
            int val=i*i;
            for(int j=val;j<=n;j++){
                dp[j]=min(dp[j],dp[j-val]+1);
            }
        }

        return dp[n];
    }
};