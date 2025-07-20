//任意取两个数相减，然后放回原数组，使最后剩下的值最小
class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        int sum = 0;
        for(int i=0;i<stones.size();i++){
            sum+=stones[i];
        }
        int target = sum/2;
        vector<int> dp(target+1,0);
        dp[0]=0;
        for(int i=0;i<stones.size();i++){
            for(int j=target;j>=stones[i];j--){
                dp[j]=max(dp[j],dp[j-stones[i]]+stones[i]);
            }
        }
        int result = sum-dp[target]-dp[target];
        return result;
    }
};