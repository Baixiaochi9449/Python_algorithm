class Solution {
    public:
        int rob(vector<int>& nums) {
            int n=nums.size();
            vector<int> dp(n+1,0);
            dp[0]=0;
            //分为偷1和不偷一的情况
            //偷1
            dp[1]=nums[0];
            if(n<2) return dp[n];
            for(int i=2;i<n;i++){
                dp[i]=max(dp[i-1],dp[i-2]+nums[i-1]);
            }
            int res1=dp[n-1]; //不偷最后一个
    
            dp[1]=0; //不偷1
            for(int i=2;i<=n;i++){
                dp[i]=max(dp[i-1],dp[i-2]+nums[i-1]);
            }
            int res2=dp[n];
    
            return max(res1,res2);
    
        }
    };