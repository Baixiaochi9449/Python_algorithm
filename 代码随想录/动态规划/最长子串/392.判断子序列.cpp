class Solution {
    public:
        bool isSubsequence(string s, string t) {
            //在t到最后之前，s有没有到最后，属于双指针？
            int i=0,j=0;
            while(i<s.size() && j<t.size()){
                if(s[i]==t[j]){
                    i++;
                    j++;
                }
                else j++;
            }
            if(i==s.size()) return true;
            else return false;
        }
    };