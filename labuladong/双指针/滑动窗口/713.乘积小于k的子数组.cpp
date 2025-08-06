//每次改变窗口的时候就判断一下
class Solution {
    public:
        int numSubarrayProductLessThanK(vector<int>& nums, int k) {
            if(k<=1) return 0;
            int left=0,right=0;
            int curnum=1;
            int result=0;
            while(right<nums.size()){
                curnum*=nums[right];
                // 如果乘积 >= k，移动左边界直到乘积 < k
                while(curnum>=k && left<=right){
                    curnum/=nums[left];
                    left++;
                }
                //此时curnum<k, 此时区间为【left,right】 ,直接计算这区间内的子数组
                result+= right-left+1;
                right++;
                
            }
            return result;
        }
    };