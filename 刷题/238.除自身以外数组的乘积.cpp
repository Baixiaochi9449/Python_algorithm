class Solution {
    public:
        vector<int> productExceptSelf(vector<int>& nums) {
            //首先计算出第一个，其他的就都能计算出来了
            int n=nums.size();
            vector<int> ans(n,0);
            ans[0]=1;
            int cout_0=0;
            if(nums[0]==0) cout_0++;
            for(int i=1;i<n;i++){
                ans[0]*=nums[i];
                if(nums[i]==0) cout_0++;
            }
            if(cout_0==0){
                for(int i=1;i<n;i++){
                    ans[i]=ans[i-1]/nums[i] * nums[i-1];
                }
            }
            else if(cout_0==1){
                int sum=1;
                int po;
                for(int i=0;i<n;i++){
                    if(nums[i]==0){
                        po=i;
                    }
                    else{
                        sum*=nums[i];
                    }
                }
                ans[po]=sum;
            }
            return ans;
        }
    };