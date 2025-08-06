//寻找sum-x的最长子数组
class Solution {
    public:
        int minOperations(vector<int>& nums, int x) {
            int sum=0;
            for(int num : nums){
                sum+=num;
            }
            int n=nums.size();
            int target=sum-x;
            int right=0,left=0;
            int cursum=0;
            int result=INT_MIN;   //设置这个值很重要
            while(right<nums.size()){
                cursum+=nums[right];
                right++;
                while(cursum>target && left<right){
                    cursum-=nums[left];
                    left++;
                }
                if(cursum==target){
                    result=max(result,right-left);
                }
            }
            if(result==INT_MIN) return -1;
            return n-result;
        }
    };