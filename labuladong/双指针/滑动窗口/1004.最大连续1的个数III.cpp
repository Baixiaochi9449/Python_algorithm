//用单指针就行啊
class Solution {
    public:
        int longestOnes(vector<int>& nums, int k) {
            int result=0;
            int left=0,right=0;
            int countone=0;
    
            while(right<nums.size()){
                if(nums[right]==1){
                    countone++;
                }
                right++;
                while(right-left-countone>k){
                    if(nums[left]==1){
                        countone--;
                    }
                    left++;
                }
                //当前肯定是一个有效的区间
                result=max(result,right-left);
            }
            return result;
    
        }
    };