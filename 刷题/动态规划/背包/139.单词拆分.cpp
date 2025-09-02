class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        //dp[i] 前i个字符组成的字符串 是否由worddict组成的
        //dp[i]=true的前提是 dp[i-word.size()]=true && [i-word.size(),i]在worddict内 要把word遍历一遍
        //提前把wordicit存储到set里
        unordered_set<string> memo(wordDict.begin(),wordDict.end());
        int n=s.size();
        vector<bool> dp(n+1,false);
        dp[0]=true;
        for(int i=0;i<n;i++){
            if(dp[i]==true){
                for(int j=i+1;j<n+1;j++){
                    string word=s.substr(i,j-i);//左开右闭
                    if(memo.find(word)!=memo.end()){ //字典中能找到
                        if(dp[i]==true) dp[j]=true;  //这里找的是j结尾的。找i结尾的是另一种方法
                    }
                }
            }
        }
        return dp[n];
    }
};
