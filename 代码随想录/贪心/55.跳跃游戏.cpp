//dp[i] 能否跳到下标为i的位置  dp[0]=true  dp[1]=(dp[0] &&dp[0]>=1) 
//if(dp[])
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n=nums.size();
        int last_id=0;
        for(int i=0;i<n;i++){
            if(i<=last_id){
                last_id=max(last_id,i+nums[i]);
            }
            else return false;
        }
        return true;
    }
};