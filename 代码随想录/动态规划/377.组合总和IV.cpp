class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<uint64_t> dp(target+1);
        dp[0]=1;
        for(int j = 0;j<target+1;j++){   //要先遍历背包，正序遍历
            for(int i = 0;i<nums.size();i++){
                if(j>=nums[i]){
                    dp[j]+=dp[j-nums[i]];
                }
            }
        }
        return dp[target];
    }
};