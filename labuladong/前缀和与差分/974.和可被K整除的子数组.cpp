class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        //target%k==0  即 (nums[i]-nums[j-1])%k==0 即 找nums[i]%k ==nums[j-1]%k 的数目，找到一个，数量加++
        int n=nums.size();
        vector<int> pre(n+1,0);
        unordered_map<int,int> memo; //mod :数量
        memo[0]=1;
        int res=0;
        for(int i=1;i<n+1;i++){
            pre[i]=pre[i-1]+nums[i-1];
            // int mod=pre[i]%; 这个取余只适用于正数，需要对负数取余
            int mod = (pre[i] % k + k) % k;
            if(memo.find(mod)!=memo.end()){
                res+=memo[mod];
            }
            memo[mod]++;
        }
        return res;
    }
};
