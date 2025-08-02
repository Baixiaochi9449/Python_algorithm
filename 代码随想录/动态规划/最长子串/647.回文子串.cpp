//暴力，截取每个子串，判断是否回文
//双指针的做法：以某个字符为中心，向两端去扩展
//dp[i][j] 以 i到j的区间内，是否为回文。  初始化为false,在遍历过程中，如果变为true就result++。同时保证j>=i
class Solution {
    public:
        int countSubstrings(string s) {
            int n=s.size();
            vector<vector<bool>> dp(n,vector<bool>(n,false));
            int result=0;
            for(int i=n-1;i>=0;i--){
                for(int j=i;j<n;j++){
                    if(s[i]==s[j]){
                        if(j-i<=1){
                            dp[i][j]=true;
                            result++;
                        } 
                        else{
                            if(dp[i+1][j-1]==true){
                                dp[i][j]=true;
                                result++;
                            }
                        }
                    }
                }
            }
            return result;
        }
    };