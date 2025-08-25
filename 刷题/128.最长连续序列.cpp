class Solution {
    public:
        int longestConsecutive(vector<int>& nums) {
            //先排序，再遍历，遍历的时候记录max
            if(nums.size()==0) return 0;
            sort(nums.begin(),nums.end());
            int res=1;
            int cur=1;
            for(int i=1;i<nums.size();i++){
                if(nums[i]==nums[i-1]) continue;
                else if(nums[i]==nums[i-1]+1){
                    cur++;
                }
                else{
                    res=max(res,cur);
                    cur=1;
                }
            }
            return max(res,cur);
        }
    };