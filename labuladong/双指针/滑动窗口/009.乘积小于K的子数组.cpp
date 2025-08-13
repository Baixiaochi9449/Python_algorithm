//找子数组，滑动窗口
//增大窗口，当大于等于k的时候缩小窗口，while里收集结果
class Solution {
    public:
        int numSubarrayProductLessThanK(vector<int>& nums, int k) {
            int res=0;
            int left=0,right=0;
            int cursum=1;
            while(right<nums.size()){
                cursum*=nums[right];
                right++;
                while(left<right && cursum>=k){
                    cursum/=nums[left];
                    left++;
                }
                //当窗口元素之积小于 k 时，窗口内元素的所有子数组都是合法子数组
                res+=right-left;
            }
            return res;
        }
    };