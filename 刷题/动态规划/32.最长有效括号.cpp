//dp[i][j]  坐标i到j范围内的有效括号。
//如果dp[i+1][j-1] 是有效的，那就看 s[i] 和s[j] 是否是（） 
//如果dp[i][j-2] 是有效的，那就看s[j-1]和s[j-2] 是不是（）
//如果dp[i+2][j] 是有效的 s[i] s[i+1]
class Solution {
    public:
        int longestValidParentheses(string s) {
            int n=s.size();
            if(n==0) return 0;
    
            vector<int> dp(n,0);
            int result=0;
            for(int i=1;i<n;i++){
                if(s[i]==')'){   //只有遇到 右括号的时候才做判断
                    //非嵌套的括号 的情况
                    if(s[i-1]=='(') {
                        if(i>=2) dp[i]=dp[i-2]+2;
                        else dp[i]=2;
                    }
                    //嵌套的括号的情况，i-dp[i-1]-1是于当前‘）’对称的位置
                    else if(i-dp[i-1]>0 && s[i-dp[i-1]-1]=='('){
                        if(i-dp[i-1]>=2) dp[i]=2+dp[i-1]+dp[i-dp[i-1]-2];
                        else dp[i]=2+dp[i-1];
                    }
    
                    result=max(result,dp[i]);
                }
            }
            return result;
        }
    };