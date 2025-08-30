class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        //把出现过的前缀和的下标 记录下来。  哈希表里面存储的是 不重复的唯一的键
        //为什么要把0 变成-1， 如果前3个前缀和为4 ， 前5个前缀和也为4，不一样能证明3-5之间的和为0吗
        //因为 要把1的数量 和0 的数量 转化为前缀和， 只有把0变为-1， 所以才能确定前缀和为0 的时候，两者相等。
        //必须要有一个初始化n+1  初始值pre[0]=0;
        int n=nums.size();
        vector<int> pre(n+1,0);
        int res=0;
        unordered_map<int,int> memo; //值---下标
        for(int i=0;i<n;i++){
            pre[i+1]=pre[i]+(nums[i]==0? -1 :1);
        }
        for(int i=0;i<n+1;i++){
            if(memo.find(pre[i])==memo.end()){
                memo[pre[i]]=i;
            }
            else{
                res=max(res,i-memo[pre[i]]);
            }
        }
        return res;
    }
};
