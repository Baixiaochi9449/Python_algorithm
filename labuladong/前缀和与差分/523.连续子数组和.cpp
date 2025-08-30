class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        //010的做法，前缀和+哈希表 
        //【i，j】  (pre[j]-pre[i-1])%k==0;  即找到pre[j]%k==pre[i-1]%k的区间。 把遍历过的都记录下来
        //还有一个限制条件是长度至少为2
        int n=nums.size();
        vector<int> pre(n+1,0);
        unordered_map<int,int> memo; //存储 pre[j]%k  : 记录下标
        memo[0]=0;  //这行代码很重要。 当前缀和为0的时候，下标是0，这个0 是虚拟下标，只有存在这个虚拟下标，才能表示【0，4】这样的数组。 因为 【1 2 3 4】 如果k=10 只有到下标 3的时候，才会把 余数0 存进去， 这样就不对了
        for(int i=1;i<n+1;i++){
            pre[i]=pre[i-1]+nums[i-1];
            if(memo.find(pre[i]%k)==memo.end()){
                memo[pre[i]%k]=i; //保存了最开始的位置， 
            }
            else{//pre[j]%k==pre[i-1]%k
                if(i-memo[pre[i]%k]>=2) return true;
            }
        }
        return false;
    }
};
