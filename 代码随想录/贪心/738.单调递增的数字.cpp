//从数字 后往前遍历，如果当前数字小于下一个数字，位数小的变9，位数大的减1
//数字从前往后遍历，如果出现一个9，后面全变9
class Solution {
    public:
        int monotoneIncreasingDigits(int n) {
            if(n<=9) return n;
            vector<int> nums;
            while(n>0){
                nums.push_back(n%10);
                n/=10;
            }
            // reverse(nums.begin(),nums.end());
            for(int i=0;i<nums.size()-1;i++){
                if(nums[i]<nums[i+1]){
                    nums[i]=9;
                    nums[i+1]--;
                }
            }
            //如果出现一个9，后面的全变成9
            for(int i=nums.size()-1;i>=0;i--){
                if(nums[i]==9){
                    while(i>=0){
                        nums[i]=9;
                        i--;
                    }
                    break;
                }
            }
            long long sum=0;
            long long fuc=1;
            for(int i=0;i<nums.size();i++){
                sum+=nums[i]*fuc;
                fuc*=10;
            }
            return sum;
        }
    };