//2个for循环？
//可以利用到有序数组的性质，从小到大
//2个指针，二分法
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int l=0;
        int r=numbers.size()-1;
        vector<int> result;
        while(l<r){
            if(numbers[l]+numbers[r]==target){
                result.push_back(l+1);
                result.push_back(r+1);
                break;
            }
            if(numbers[l]+numbers[r]>target) r--;
            if(numbers[l]+numbers[r]<target) l++;
        }
        return result;
    }
};