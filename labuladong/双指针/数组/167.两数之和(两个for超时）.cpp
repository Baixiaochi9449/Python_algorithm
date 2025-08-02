//2个for循环？
class Solution {
    public:
        vector<int> twoSum(vector<int>& numbers, int target) {
            vector<int> result;
            int n=numbers.size();
            for(int i=0;i<n;i++){
                for(int j=i+1;j<n;j++){
                    if(numbers[i]+numbers[j]==target){
                        result.push_back(i+1);
                        result.push_back(j+1);
                    }
                }
            }
            return result;
        }
    };