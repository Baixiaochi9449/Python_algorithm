//2个循环，把i前面的数全都遍历一遍
class Solution {
    public:
        int lengthOfLIS(vector<int>& nums) {
            int n=nums.size();
            vector<int> dp(n,1);
            int result=1;
            for(int i=1;i<n;i++){
                for(int j=0;j<i;j++){
                    if(nums[j]<nums[i]) dp[i]=max(dp[j]+1,dp[i]);
                    result=max(dp[i],result);
                }
            }
            return result;
        }
    };