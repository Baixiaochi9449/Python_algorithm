//输出的又不是数字，怎么能用dp
//截取每一段，然后判断是否是回文的
class Solution {
    public:
        bool isvalid(string str){
            int i=0,j=str.size()-1;
            while(i<=j){
                if(str[i]!=str[j]) return false;
                i++;
                j--;
            }
            return true;
        }
    
        string longestPalindrome(string s) {
            if(s.size()==1) return s;
            int max_count=0;
            string max_str;
            for(int i=0;i<s.size();i++){
                for(int j=i;j<s.size();j++){
                    string str=s.substr(i,j-i+1);
                    if(isvalid(str)){
                        if(str.size()>max_count){
                            max_count=str.size();
                            max_str=str;
                        }
                    }
                }
            }
            return max_str;
        }
    };