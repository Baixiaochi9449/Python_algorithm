//回溯：先回溯来一遍。 每次选择一个字符或2个字符
//在 backtracking 函数中，你使用了 for(int i=index;i<s.size();i++)，这会导致重复处理同一位置的字符，从而产生错误的结果。回溯的目的是尝试不同的选择路径，而不是遍历所有可能的起始位置

////几种就是dp。dp[i] 以i为结尾的 可以有几种编码 dp[i]=dp[i-1]+dp[i-2] 
//第一个元素为0，就直接0 ，如果s[i]==0 dp[i]=dp[i-2] 
//定义dp[i] 是前i个元素，即 0--i-1 ，所以dp[0]就是前0个元素。 但是要初始化为1
class Solution {
    public:
        int numDecodings(string s) {
            int n=s.size();
            vector<int> dp(n+1,0);
            if(s[0]=='0') return 0;
            dp[0]=1;
            for(int i=1;i<=n;++i){
                if(s[i-1]!='0') dp[i]+=dp[i-1];
                
                if(i>1 && s[i-2]!='0'){
                    int sum=(s[i-2]-'0')*10 +s[i-1]-'0';
                    if(sum<=26) dp[i]+=dp[i-2];
                }
            }
            return dp[n];
        }
    };