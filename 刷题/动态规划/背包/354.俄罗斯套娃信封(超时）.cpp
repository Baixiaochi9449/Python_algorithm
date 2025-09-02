class Solution {
public:
    static bool compare(vector<int>& a, vector<int>& b){
        if(a[0]==b[0]) return a[1]<b[1];
        else return a[0]<b[0];
    }
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        //求两个维度都是递增序列
        //dp[i] 以第i个信封结尾的 装的最多的信封数量
        //初始化为1
        sort(envelopes.begin(),envelopes.end(),compare);
        int n=envelopes.size();
        vector<int> dp(n,1);
        int res=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                if(envelopes[i][0]>envelopes[j][0] && envelopes[i][1]>envelopes[j][1]){
                    dp[i]=max(dp[i],dp[j]+1);
                }
            }
            res=max(res,dp[i]);
        }
        return res;
    }
};
