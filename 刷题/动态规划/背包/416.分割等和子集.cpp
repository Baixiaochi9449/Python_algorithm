class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            sum+=nums[i];
        }
        int target=sum/2;
        if(sum%2!=0) return false;
        //0-1背包 dp[i] 背包容量为i的时候的最多能装的价值
        vector<int> dp(target+1,0);
        for(int i=0;i<n;i++){
            for(int j=target;j>=nums[i];j--){
                dp[j]=max(dp[j],dp[j-nums[i]]+nums[i]);
            }
        }
        if(dp[target]==target) return true;
        else return false;
    }
};
