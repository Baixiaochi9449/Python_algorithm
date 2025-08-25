class Solution {
    public:
        int subarraySum(vector<int>& nums, int k) {
            int res=0;
            int n= nums.size();
            for(int i=0;i<n;i++){
                int curnum=0;
                for(int j=i;j<n;j++){
                    curnum+=nums[j];
                    if(curnum==k) res++;
                }
            }
            return res;
        }
    };