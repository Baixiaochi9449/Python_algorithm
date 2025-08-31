class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        //总和=sum   target=sum-5  和为target的最长子数组 的长度
        int n=nums.size();
        vector<int> pre(n+1,0);
        int res=-1;
        unordered_map<int,int> memo; //值 ： 下标
        memo[0]=0;
        int sum=0;
        for(int i=1;i<n+1;i++){
            sum+=nums[i-1];
        }
        int target=sum-x;
        if(target<0) return -1;
        if(target==0) return n;
        //和为target  即寻找pre[i]-target 的下标  存过的就不存了（为了保证都只存最前面的）
        for(int i=1;i<n+1;i++){
            pre[i]=pre[i-1]+nums[i-1];
            if(memo.find(pre[i]-target)!=memo.end()){
                res=max(res,i-memo[pre[i]-target]);
            }
            memo[pre[i]]=i;
        }
        if(res==-1) return res;
        else return n-res;
    }
};
