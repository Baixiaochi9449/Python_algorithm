//最后一个房间，与第一个房间，需要考虑//如果偷第一个房间，最后一个不能偷，
//可以选偷第一个房间的情况，和不偷第一个房间的情况

class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n+1);
        int result_1,result_2;
        dp[0]=0; //0个房子
        dp[1]=nums[0]; //偷第一个房间
        if(n<2) return dp[n];
        
        for(int i=2;i<n;i++){
            dp[i]=max(dp[i-1],dp[i-2]+nums[i-1]);
        }
        result_1=dp[n-1];

        dp[1]=0; //不偷第一个
        for(int i=2;i<=n;i++){
            dp[i]=max(dp[i-1],dp[i-2]+nums[i-1]);
        }
        result_2 = dp[n];
        return max(result_1,result_2);
    }
};