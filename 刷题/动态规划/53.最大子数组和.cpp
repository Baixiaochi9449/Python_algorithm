//最大和的连续
//dp[i] 以i结尾的，最大的和
//dp[i]=max(dp[i],dp[i-1]+nums[i])
//初始化的时候全都等于自身
class Solution {
    public:
        int maxSubArray(vector<int>& nums) {
            int n=nums.size();
            vector<int> dp(n);
            for(int i=0;i<n;i++){
                dp[i]=nums[i];
            }
            int result=nums[0];
            for(int i=1;i<n;i++){
                dp[i]=max(dp[i],dp[i-1]+nums[i]);
                result=max(result,dp[i]);
            }
            return result;
        }
    };