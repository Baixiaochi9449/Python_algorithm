//dp [i] 以i结尾的最大连续子数组
//dp[i]=max(nums[i],dp[i-1]+nums[i])
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        //以i结尾的最大的连续数组和 dp[i]
        int n=nums.size();
        vector<int> dp(n);
        int res=nums[0];
        dp[0]=nums[0];
        for(int i=1;i<n;i++){
            dp[i]=max(nums[i],dp[i-1]+nums[i]);
            res=max(res,dp[i]);
        }
        return res;
    }
};
