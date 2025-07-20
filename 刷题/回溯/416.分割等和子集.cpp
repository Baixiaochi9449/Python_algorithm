//先算总和=22， 那么除以一半就是11， 其实就是找，哪些元素相加=11，找到了返回true,没找到就返回false
//回溯可以解决。 但是时间复杂度太高。 
//背包的话，背包容量11，遍历物品，来装满这个背包？？怎么做？
class Solution {
private:
    bool backtracking(vector<int>& nums,int target,int index,int cur_sum){
        for(int i=index;i<nums.size();i++){
            if (i > index && nums[i] == nums[i - 1]) continue;  //层间去重
            if(cur_sum+nums[i]==target) return true;
            if(cur_sum+nums[i]>target) return false;  //直接返回false,因为排序了，这个已经是最小的
            cur_sum+=nums[i];
            if(backtracking(nums,target,i+1,cur_sum)){
                return true;
            }
            cur_sum-=nums[i];
        }
        return false;
    }
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        int max_num=0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            max_num=max(max_num,nums[i]);
        }
        if(sum%2!=0) return false;
        int target = sum/2;
        if(max_num>target) return false;
        sort(nums.begin(),nums.end());
        return backtracking(nums,target,0,0);
    }
};