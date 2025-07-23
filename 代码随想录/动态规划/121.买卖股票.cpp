class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minprice=1000000;
        int maxprit=0;
        for(int price : prices){
            maxprit=max(maxprit,price-minprice);  //这里使用的minprice是前面遍历过的最小的price
            minprice=min(minprice,price);
        }
        return maxprit;
    }
};


//0代表持有股票
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>> dp(n,vector<int>(2,0));
        dp[0][0]=-prices[0];
        dp[0][1]=0;
        for(int i=1;i<n;i++){
            dp[i][0]=max(dp[i-1][0],-prices[i]); //找到最小的价格
            dp[i][1]=max(dp[i-1][1],dp[i-1][0]+prices[i]);
        }
        return max(dp[n-1][0],dp[n-1][1]);
    }
};