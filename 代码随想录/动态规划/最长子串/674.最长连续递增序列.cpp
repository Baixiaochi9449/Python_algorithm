//dp[i] 以i结尾的最长连续递增子序列 dp[i]=d[i-1]+1
class Solution {
    public:
        int findLengthOfLCIS(vector<int>& nums) {
            int n=nums.size();
            vector<int> dp(n,1);
            int result=1;
            for(int i=1;i<n;i++){
                if(nums[i-1]<nums[i]) dp[i]=dp[i-1]+1;
                result=max(result,dp[i]);
            }
            return result;
        }
    };