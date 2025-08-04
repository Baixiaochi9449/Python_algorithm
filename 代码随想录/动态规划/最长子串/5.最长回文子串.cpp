//暴力截取每一段，判断是否回文
//dp 分很多情况
//dp[i][j] i到j的范围内是否是回文的   if(==)   中间有<=1个元素 true  else dp[i][j]=dp[i+1][j-1]
//从下到上，从左到右
//初始化i i的位置都是回文的。   
//结果 ；只要是回文的，result=max(result,j-i+1)  curstr=substr(i,j-i+1)
class Solution {
public:
    string longestPalindrome(string s) {
        if(s.size()<2) return s;
        int n=s.size();
        vector<vector<bool>> dp(n,vector<bool>(n,false));
        for(int i=0;i<n;i++){
            dp[i][i]=true;
        }
        int count=1;
        int begin=0;
        // 枚举长度，从L=2开始。  循环左边界i， 知道L知道i就知道j
        for(int L=2;L<=n;L++){
            for(int i=0;i<n;i++){
                int j=L+i-1;
                if(j>=n) break;
                if(s[i]==s[j]){
                    if(j-i<=2) {
                        dp[i][j]=true;
                        if(j-i+1>count){
                            count=j-i+1;
                            begin=i;
                        }
                    }
                    else{
                        dp[i][j]=dp[i+1][j-1];
                        if(dp[i][j]==true && j-i+1>count){
                            count=j-i+1;
                            begin=i;
                        }
                    }
                }
            }
        }
        return s.substr(begin,count);
    }
};