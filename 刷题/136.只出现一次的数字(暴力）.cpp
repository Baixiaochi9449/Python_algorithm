class Solution {
public:
    int singleNumber(vector<int>& nums) {
        if(nums.size()==1) return nums[0];
        sort(nums.begin(),nums.end());
        int i=0;
        int res;
        while(i<nums.size()-1){
            int cout=1;
            while(nums[i]==nums[i+1]){
                cout++;
                i++;
            }
            if(cout==1){
                res=nums[i];
                break;
            }
            i++;
        }
        return res;
    }
};
