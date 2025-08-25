class Solution {
    public:
        int firstMissingPositive(vector<int>& nums) {
            sort(nums.begin(),nums.end());
            //先判断无1的情况
            if(nums[0]>1) return 1;
            int idx=0;
            while(idx<nums.size() && nums[idx]<=0) idx++;
            if(idx==nums.size()) return 1;
            //从idx处就都是>0的了
            if(nums[idx]>1) return 1;
            int cout=1;
            unordered_set<int> memo;
            while(idx<nums.size()){
                if(idx>0 && nums[idx]==nums[idx-1]){
                    idx++;
                    continue;
                }
                if(nums[idx]==cout){
                    idx++;
                    cout++;
                }
                else if(nums[idx]!=cout) break;
            }
            return cout;
        }
    };