//使用暴力做一遍
//二分法其实也是暴力，只不过是次数少的暴力，也是挨个试试，只不过是跳的距离大了
class Solution {
    public:
        int minSubArrayLen(int target, vector<int>& nums) {
            int min_count=1000;
            for(int i=0;i<nums.size();i++){
                int sum=nums[i];
                if(sum>=target){
                    min_count=1;
                    break;
                }
    
                int curcout=1;
                for(int j=i+1;j<nums.size();j++){
                    sum+=nums[j];
                    curcout++;
                    if(sum>=target){
                        min_count=min(min_count,curcout);
                        break;
                    }
                }
            }
            if(min_count==1000) return 0;
            else return min_count;
        }
    };