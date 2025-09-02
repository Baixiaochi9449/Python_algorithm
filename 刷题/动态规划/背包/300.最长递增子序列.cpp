//不是相邻的，要把i前面的数全都遍历一遍
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        //dp[i]  以i结尾的 最长递增序列的长度
        int n=nums.size();
        vector<int> dp(n,1);
        int res=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                if(nums[j]<nums[i]){
                    dp[i]=max(dp[i],dp[j]+1);
                }
            }
            res=max(res,dp[i]);
            
        }
        return res;
    }
};
