//dp[i] 以下标i结尾的最大乘积
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp_max(n);
        vector<int> dp_min(n);
        int res=nums[0];
        dp_max[0]=nums[0];
        dp_min[0]=nums[0];
        for(int i=1;i<n;i++){
            if(nums[i]<0){
                int temp=dp_max[i-1];
                dp_max[i-1]=dp_min[i-1];
                dp_min[i-1]=temp;
            }
            dp_min[i]=min(dp_min[i-1]*nums[i],nums[i]);
            dp_max[i]=max(dp_max[i-1]*nums[i],nums[i]);
            res=max(res,dp_max[i]);
        }
        return res;
    }
};
