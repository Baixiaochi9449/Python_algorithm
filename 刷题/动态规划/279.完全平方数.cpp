//完全背包。 物品为1 4 9 ... 背包n ,先遍历物品
//求组成背包的最小的物品数量， dp[j]=min(dp[j],dp[j-物品]+1) 
class Solution {
public:
    int numSquares(int n) {
        vector<int> dp(n+1,INT_MAX);
        dp[0]=0;
        for(int i=1;i*i<=n ;i++){
            for(int j=i*i;j<=n;j++){
                dp[j]=min(dp[j],dp[j-i*i]+1);
            }
        }
        return dp[n];
    }
};