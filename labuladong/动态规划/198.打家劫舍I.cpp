//dp[j] 道第j个房间的时候 能偷的最大金额
class Solution {
    public:
        int rob(vector<int>& nums) {
            int n=nums.size();
            vector<int> dp(n+1,0);   //长度为j的数组，能偷的最多的钱
            dp[0]=0;
            dp[1]=nums[0];
            for(int i=2;i<n+1;i++){
                dp[i]=max(dp[i-1],dp[i-2]+nums[i-1]);
            }
            return dp[n];
        }
    };