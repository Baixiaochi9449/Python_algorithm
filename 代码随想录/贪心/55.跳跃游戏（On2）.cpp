//dp[i] 能否跳到下标为i的位置  dp[0]=true  dp[1]=(dp[0] &&dp[0]>=1) 
//if(dp[])
class Solution {
public:
    bool canJump(vector<int>& nums) {
        if(nums.size()<2) return true;

        int n=nums.size();
        vector<bool> dp(n);
        //初始化
        for(int i=0;i<=nums[0] && i<n;i++){
            dp[i]=true;
        }
        for(int k=1;k<n-1;k++){
            if(dp[k]){
                for(int i=1;i<=nums[k] && k+i<n;i++){
                    dp[k+i]=true;
                    if(dp[n-1]==true) return true;
                }
            }
        }
        return dp[n-1];
    }
};