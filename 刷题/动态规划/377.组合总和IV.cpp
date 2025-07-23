//完全背包的组合数 先遍历背包，再遍历物品  都是正序
//dp[i] 凑成i的 组合数的个数  dp[4]=dp[3]+dp[2]+dp[1]  dp[j]+=dp[j-nums[i]]
class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<uint64_t> dp(target+1,0);
        dp[0]=1;
        for(int j=1;j<=target;j++){
            for(int i=0;i<nums.size();i++){
                if(j>=nums[i]) dp[j]+=dp[j-nums[i]];
                
            }
        }
        return dp[target];
    }
};