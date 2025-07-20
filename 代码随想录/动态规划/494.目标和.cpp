//分为2个子集， 加法子集left和减法子集right ,left+right = sum ,left-right=target. 所以left=(sum+target)/2
//如果不能整除，那么就不能凑成target,方法=0；
//题意转化：把容量为left的背包装满 有几种方法？ dp[j]+=dp[j-nums[i]];
//0-1背包，先遍历物品，再倒序遍历背包
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum=0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
        }
        if((sum+target)%2!=0 ) return 0;
        int left = (sum+target)/2;
        if(left<0) return 0;
        vector<int> dp(left+1,0);
        dp[0]=1;
        for(int i=0;i<nums.size();i++){
            for(int j=left;j>=nums[i];j--){  //一定要包含相等的情况
                dp[j]+=dp[j-nums[i]];
            }
        }
        return dp[left];
    }
};