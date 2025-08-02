//回溯，找到每个长度为t.size()的字符串，来比较
//dp[i][j] 以i-1 为结尾的s中 有多少个 以j-1为结尾的t
class Solution {
    public:
        int numDistinct(string s, string t) {
            int n=s.size();
            int m=t.size();
            vector<vector<int>> dp(n+1,vector<int>(m+1));
            for(int i=0;i<=n;i++){  //第一列 t=0 都是1
                dp[i][0]=1;
            }
            for(int j=1;j<=m;j++){  //第一行 s=0 都是0
                dp[0][j]=0;
            }
            for(int i=1;i<=n;i++){
                for(int j=1;j<=m;j++){
                    if(s[i-1]==t[j-1]) dp[i][j]=dp[i-1][j-1]+dp[i-1][j];//使用s[i-1]和不使用s[i-1]
                    else dp[i][j]=dp[i-1][j]; //s的前i-1个元素，即到下标i-2 , t的前j-1个元素，即到下标j-1。不相等就不使用s[i-1] ,所以取的是s[i-2]下标处的dp
                }
            }
            return dp[n][m];
        }
    };