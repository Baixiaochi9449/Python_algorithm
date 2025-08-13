//暴力，截取每个子串，判断是否回文
//双指针的做法：以某个字符为中心，向两端去扩展
//dp[i][j] 以 i到j的区间内，是否为回文。  初始化为false,在遍历过程中，如果变为true就result++。同时保证j>=i
class Solution {
    public:
        int isvalid(string s,int l,int r){
            int res=0;
            while(l>=0 && r<s.size()){
                if(s[l]==s[r]){
                    res++;
                    l--;
                    r++;
                }
                else return res;
            }
            return res;
        }
        int countSubstrings(string s) {
            int res=0;
            for(int i=0;i<s.size();i++){
                res+=isvalid(s,i,i);
                if(i+1<s.size()) res+=isvalid(s,i,i+1);
            }
            return res;
        }
    };