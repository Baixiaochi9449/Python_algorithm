//2次是5  k次就是2*k +1
//最后的答案是dp[n-1][2k] 
//每次k+2, 取值为 k+1表示买入，k+2表示卖出
class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>> dp(n,vector<int>(2*k+1,0));
        dp[0][0]=0;
        for(int j=1;j<2*k+1;j+=2){
            dp[0][j]=-prices[0];
            dp[0][j+1]=0;
        }

        for(int i=1;i<n;i++){
            for(int j=0;j<2*k-1;j+=2){  //注意j+=2所以不要越界
                dp[i][j+1]=max(dp[i-1][j+1],dp[i-1][j]-prices[i]);
                dp[i][j+2]=max(dp[i-1][j+2],dp[i-1][j+1]+prices[i]);
            }
        }
        return dp[n-1][2*k];
    }
};