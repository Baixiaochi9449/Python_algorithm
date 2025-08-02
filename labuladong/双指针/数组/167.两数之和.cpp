//2个for循环？
//可以利用到有序数组的性质，从小到大
class Solution {
    public:
        vector<int> twoSum(vector<int>& numbers, int target) {
            vector<int> result;
            int n=numbers.size();
            int i=0,j=n-1;
            while(i<j){
                if(numbers[i]+numbers[j]>target) j--;
                if(numbers[i]+numbers[j]<target) i++;
                if(numbers[i]+numbers[j]==target) {
                    result.push_back(i+1);
                    result.push_back(j+1);
                    break;
                }
            }
            return result;
        }
    };