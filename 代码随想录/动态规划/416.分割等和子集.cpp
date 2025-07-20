//先算总和=22， 那么除以一半就是11， 其实就是找，哪些元素相加=11，找到了返回true,没找到就返回false
//回溯可以解决。 但是时间复杂度太高。 
//背包的话，背包容量11，遍历物品，来装满这个背包？？怎么做？
//dp[1] 容量为1的时候，装的最大物品的价值。 
//直接用背包问题做，最后判断 dp[11]是否等于11
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum=0;
        int max_num=0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            max_num=max(nums[i],max_num);
        }
        if(sum%2!=0) return false;
        int target = sum/2;
        if(target<max_num) return false;
        vector<int> dp(target+1,0);
        dp[0]=0;
        for(int i=0;i<nums.size();i++){
            for(int j=target;j>0 && nums[i]<=j;j--){    //背包要倒序遍历
                dp[j]=max(dp[j],dp[j-nums[i]]+nums[i]);
            }
        }
        return dp[target]==target;
    }
};