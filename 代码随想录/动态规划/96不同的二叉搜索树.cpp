//最后只返回数字，所以直接动态规划
//dp[0] n=0的时候的种数  dp[0]=1  dp[1]=1  dp[2]=2  
//dp[3]= 以1做顶点，左区间[] 右区间[2,3] dp[3]=dp[0]*dp[2] +dp[1]*dp[1] +dp[2]*dp[1]
class Solution {
public:
    int numTrees(int n) {
        vector<int> dp(n+1);
        dp[0]=1;
        dp[1]=1;
        if(n<2) return dp[n];
        
        dp[2]=2;
        for(int i=3;i<=n;i++){
            for(int j=1;j<=i;j++){
                dp[i]+=dp[j-1]*dp[i-j];
            }
        }
        return dp[n];
    }
};