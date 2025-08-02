//暴力，截取每个子串，判断是否回文
//双指针的做法：以某个字符为中心，向两端去扩展
class Solution {
    public:
        int countSubstrings(string s) {
            int n=s.size();
            int result=0;
            for(int k=0;k<n;k++){
                //两边同时变大
                int i=k,j=k;
                while(i>=0 && j<n && s[i]==s[j]){
                    result++;
                    i--;
                    j++;
                }
                i=k;
                j=k+1;
                while(i>=0 && j<n && s[i]==s[j]){
                    result++;
                    i--;
                    j++;
                }  
            }
            return result;
        }
    };