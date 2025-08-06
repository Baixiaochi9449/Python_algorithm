class Solution {
    public:
        bool containsNearbyDuplicate(vector<int>& nums, int k) {
            unordered_map<int,int> memo;
            for(int i=0;i<nums.size();i++){
                if(memo.count(nums[i])){
                    if(i-memo[nums[i]]<=k) return true;
                }
                memo[nums[i]]=i;
            }
            return false;
        }
    };