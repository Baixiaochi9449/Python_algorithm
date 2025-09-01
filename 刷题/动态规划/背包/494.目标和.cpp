class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        //target=3  那么  减+加=n   加-减=target  加=(n+target)/2;
        int sum=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            sum+=nums[i];
        }
        int t=(sum+target)/2;
        if((sum+target)%2!=0) return 0;
        if(t<0) return 0;
        vector<int> dp(t+1,0);
        dp[0]=1;
        //现在的目标，有几种选择方式，可以把t大小的背包装满
        //dp[i] 把容量为i的背包装满，有多少种方法？ 
        //如果现在考虑物品（价值1） dp[5]=dp[4] 如果现在考虑物品（价值2） 那么dp[5]=dp[3]
        //dp[j]+=dp[j-nums[i]]
        for(int i=0;i<n;i++){
            for(int j=t;j>=nums[i];j--){
                dp[j]+=dp[j-nums[i]];
            }
        }
        return dp[t];
    }
};
