// 输出的又不是数字，怎么能用dp
// 截取每一段，然后判断是否是回文的
class Solution {
    public:
        string longestPalindrome(string s) {
            int n = s.size();
            if (n < 2)
                return s;
    
            // dp[i][j] :i到j区间的子串 是否回文 true/false
            vector<vector<bool>> dp(n, vector<bool>(n));
            // 初始化：单个字符都是回文的。 如何表示单个字符？  dp[i][i]
            for (int i = 0; i < n; i++) {
                dp[i][i] = true;
            }
            int max_len=1;
            int begin=0;
            // 枚举长度，从L=2开始。  循环左边界i， 知道L知道i就知道j
            for (int L = 2; L <= n; L++) {
                for (int i=0;i<n;i++){
                    //L=j-i+1
                    int j=L+i-1;
                    if(j>=n) break; //右边界越界就跳出循环
                    
                    //知道i和j了，接下来就判断dp[i][j]是true还是false
                    //1、
                    if(s[i]!=s[j]) {
                        dp[i][j]=false;
                    }
                    //2、
                    else{
                        //2.1 只有3个字符/2个字符
                        if(j-i<3) dp[i][j]=true;
                        //2.2
                        else dp[i][j]=dp[i+1][j-1];
                    }
                    //当前已经确定了dp[i][j]的值，所以开始保存 当前的起始位置，和长度
                    if(dp[i][j] && L>max_len){
                        max_len=L;
                        begin=i;
                    }
                }
            }
            return s.substr(begin,max_len);
        }
    };