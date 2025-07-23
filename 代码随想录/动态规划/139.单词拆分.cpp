#include <vector>
#include <string>
#include <unordered_set>
using namespace std;

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> dict(wordDict.begin(), wordDict.end());
        int max_len = 0;
        for (const string& word : wordDict) {
            max_len = max(max_len, (int)word.size());
        }
        
        int n = s.size();
        vector<bool> dp(n + 1, false);
        dp[0] = true; // 空字符串可以被拆分
        
        for (int i = 1; i <= n; i++) {
            for (int j = i - 1; j >= max(0, i - max_len); j--) {
                if (dp[j] && dict.count(s.substr(j, i - j))) {  //只要有一个符合条件，dp[i]=true
                    dp[i] = true;
                    break;
                }
            }
        }
        
        return dp[n];
    }
};