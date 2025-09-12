//返回类型为bool的回溯
class Solution {
private:
    vector<int> everysum;
    bool backtracking(vector<int>& nums,int target,int start,int k){
        if(start==nums.size()){  //数字遍历完了
            for(int i=0;i<k;i++){
                if(everysum[i]!=target) return false;
            }
            return true;
        }

        for(int i=0;i<k;i++){
            if(nums[start]+everysum[i]>target) continue;
            everysum[i]+=nums[start];
            if(backtracking(nums,target,start+1,k)){
                return true;
            }
            everysum[i]-=nums[start];
        }
        return false;
    }
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        //递归数字，相当于遍历数字。 在每次递归的时候，for(每个桶)， 相当于以数字的视角，每个数字可以放入4个桶里。 放入4个桶的过程是并行的，所以可以在层间选择几种情况
        //所以在分析这种题的时候，可以选择视角，把谁放入谁有几种选择
        int sum=0;
        int maxnum=0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            maxnum=max(maxnum,nums[i]);
        }
        int target=sum/k;
        if(sum%k!=0) return false;
        if(maxnum>target) return false;
        everysum=vector<int>(k,0);
        return backtracking(nums,target,0,k);

    }
};
