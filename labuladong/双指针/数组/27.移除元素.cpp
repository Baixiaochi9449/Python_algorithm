//因为移除之后，后面的元素是空的。 所以一个指针从前往后，一个从后往前。
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        if(nums.size()==0) return 0;
        int slow=0;
        int fast=0;
        while(fast<nums.size()){
            if(nums[fast]!=val){
                nums[slow]=nums[fast];
                slow++;
            }
            fast++;
        }
        return slow;
    }
};