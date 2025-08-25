class Solution {
    public:
        int lengthOfLongestSubstring(string s) {
            //用map来记录重复子串
            //就是双指针啊， 不重复的时候j++,重复的时候i++,直到不重复为止 ,同时维护map
            if(s=="") return 0;
            int i=0,j=0;
            int res=1;
            unordered_map<char,int> memo;
            while(j<s.size()){
    
                while(memo.count(s[j])>0){
                    // memo[s[i]]--;  //只能统计键是否存在
                    memo.erase(s[i]);
                    i++;
                }
                res=max(res,j-i+1);
                memo[s[j]]++;
                j++;
            }
            return res;
        }
    };