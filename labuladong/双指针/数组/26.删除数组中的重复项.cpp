//两个指针，一个pre 一个cur, 当pre==cur , pre不动，cur++,  当两个不相等，把slow++; 然后把fast赋值给slow . fast每次都动
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size()==0) return 0;
        int slow=0,fast=0;
        while(fast<nums.size()){
            if(nums[slow]!=nums[fast]){
                slow++;
                nums[slow]=nums[fast];
            }
            fast++;
        }
        return slow+1;
    }
};