//动态规划：dp[i] 0-第i个房子，的最多的钱
//dp[0]=0  dp[1]=max(dp[0],num[1])  dp[2]只能从dp[0]推出来 dp[3]只能
class Solution {
public:
    int rob(vector<int>& nums) {
        vector<int> dp(nums.size());
        if(nums.size()==0) return 0;
        if(nums.size()==1) return nums[0];
        dp[0]=nums[0];
        dp[1]=max(nums[0],nums[1]);
        for(int i=2;i<nums.size();i++){
            dp[i]=max(dp[i-2]+nums[i],dp[i-1]);
        }
        return dp[nums.size()-1];
    }
};