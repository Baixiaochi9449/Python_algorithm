class Solution {
    public:
        void nextPermutation(vector<int>& nums) {
            //从后往前找
            //一个很愚蠢的方法： 把所有的全排列都找出来，然后以string的形式存储在一个数组里，然后找位置
            //原地换：从最后一个开始，找到前面第一个比它小的数字
            //找前一个比它小的数字
            int n=nums.size();
            int need_change=n-1;
            int nextidx=-1;
            for(int i=n-1;i>=0 ;i--){   //找每一个位置可能替换的位置
                for(int j=i-1;j>=0;j--){
                    if(nums[j]<nums[i]){
                        if(j>nextidx){  //取更靠右的
                            nextidx=j;
                            need_change=i;
                        }
                        break;
                    }
                }
            }
    
            if(nextidx==-1){
                sort(nums.begin(),nums.end());
            }
            else{
                int temp=nums[need_change];
                nums[need_change]=nums[nextidx];
                nums[nextidx]=temp;
                sort(nums.begin()+nextidx+1,nums.end());
            }
        }
    };