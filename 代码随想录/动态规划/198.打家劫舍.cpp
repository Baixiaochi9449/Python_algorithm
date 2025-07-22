//求最大金额. dp[i] 长度为i的数组，能拿到的最大的钱。  dp[0]=0 dp[1]=nums[0] dp[2]=max(nums[0],nums[1])   递推 dp[j] = max(dp[j-1],dp[j-2]+nums[j-1]);
//这个属于背包问题吗？感觉没有物品啊
class Solution {
public:
    int rob(vector<int>& nums) {
        int n =nums.size();
        vector<int> dp(n+1,0);
        dp[1]=nums[0];
        if(n<2) return dp[n];
        for(int j=2;j<=n;j++){
            dp[j]=max(dp[j-1],dp[j-2]+nums[j-1]);
        }
        return dp[n];
    }
};