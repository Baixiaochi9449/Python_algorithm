class Solution {
    public:
        bool containsNearbyDuplicate(vector<int>& nums, int k) {
            //仅仅维护一个长度为k的窗口，只要有重复元素就直接返回true
            int  left=0,right=0;
            unordered_set<int> memo;
            while(right<nums.size()){
                if(memo.count(nums[right])){
                    return true;
                }
                memo.insert(nums[right]);
                right++;
                while(right-left>k){
                    memo.erase(nums[left]);
                    left++;
                }
            }
            return false;
        }
    };