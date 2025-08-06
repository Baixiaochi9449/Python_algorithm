//判断是否有无重复字符，没有就一直增大窗口，并记录当前长度。 如果有重复字符，减小窗口，直到无重复字符。
class Solution {
    public:
        int lengthOfLongestSubstring(string s) {
            if(s.size()==0) return 0;
            unordered_set<char> memo;
            int result=0;
            int left=0,right=0;
            while(right<s.size()){
                char c = s[right];
    
                while(memo.count(c) && left<right){
                    char d =s[left];
                    memo.erase(d);
                    left++;
                }
    
                memo.insert(c);
                result=max(result,right-left+1);
                right++;
            }
            return result;
        }
    };