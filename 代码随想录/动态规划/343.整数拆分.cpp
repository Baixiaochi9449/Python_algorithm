//dp[0]=0; dp[1]=0 ;dp[2]=1 dp[3]=2  d[4]= max(1*3,2*2) dp[5]=max(1*4,1*2*2 , 2*3,2*1*3)
//int j=0   dp[i]=max(j*(i-j),j*dp[i-j])
class Solution {
public:
    int integerBreak(int n) {
        vector<int> dp(n+1,0);
        dp[0]=0;
        dp[1]=0;
        dp[2]=1;
        if(n<=2) return dp[n];
        for(int j=3;j<=n;j++){
            for(int i=1;i<j;i++){
                int temp=max(i*(j-i),i*dp[j-i]);
                dp[j]=max(dp[j],temp);
            }
        }
        return dp[n];
    }
};