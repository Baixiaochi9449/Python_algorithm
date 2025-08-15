//与覆盖范围有关，int length 记录最长的距离
class Solution {
    public:
        bool canJump(vector<int>& nums) {
            int length=0;
            for(int i=0;i<nums.size();i++){
                length=max(length,nums[i]+i);
                if(length>=nums.size()-1) return true;
                if(length<=i) return false;
            }
            return false;
        }
    };