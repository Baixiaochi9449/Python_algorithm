class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        //前缀和+哈希的典型题目
        //[i,j]  pre[j]-pre[i-1]=k  所以 pre[i-1]=pre[j]-k  想要找以j结尾的和为k的子数组的个数==寻找前缀和为pre[j]-k的前缀和 的个数
        int n=nums.size();
        vector<int> pre(n+1,0);
        unordered_map<int,int> memo; //存储 前缀和：数量
        memo[0]=1;
        int count=0;
        for(int i=1;i<n+1;i++){
            pre[i]=pre[i-1]+nums[i-1];
            if(memo.find(pre[i]-k)!=memo.end()){
                count+=memo[pre[i]-k];
            }
            memo[pre[i]]++;
        }
        return count;
    }
};
