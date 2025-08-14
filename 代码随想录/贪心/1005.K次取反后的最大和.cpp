class Solution {
public:
    static bool compare(int a,int b){
        return abs(a)>abs(b);   //按绝对值大小排序
    }
    int largestSumAfterKNegations(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end(),compare);
        int result=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]<0 && k>0){
                nums[i]*=-1;
                k--;
            }
            if(i!=nums.size()-1) result+=nums[i];
        }
        if(k%2==1) nums[nums.size()-1]*=-1;
        result+=nums[nums.size()-1];
        return  result;
    }
};