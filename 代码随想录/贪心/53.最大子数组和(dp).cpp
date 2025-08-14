//dp [i] 以i结尾的最大连续子数组
//dp[i]=max(nums[i],dp[i-1]+nums[i])
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n,0);
        dp[0]=nums[0];
        int res=nums[0];
        for(int i=1;i<n;i++){
            dp[i]=max(nums[i],dp[i-1]+nums[i]);
            res=max(dp[i],res);
        }
        return res;
    }
};