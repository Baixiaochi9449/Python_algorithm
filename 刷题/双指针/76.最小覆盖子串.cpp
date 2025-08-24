class Solution {
    public:
        string minWindow(string s, string t) {
            //先记录need
            unordered_map<char,int> need,window;
            for(char c : t){
                need[c]++;
            }
            int l=0,r=0;
            int start=0,len=INT_MAX;
            int valid=0;  //记录窗口中满足的个数，当valid==need.size() 就说明完全覆盖了范围
            while(r<s.size()){
                char c =s[r];
                r++;
                if(need.count(c)){  //c是需要的元素
                    window[c]++;
                    if(window[c]==need[c]){
                        valid++;
                    }
                }
    
                while(valid==need.size()){  //该缩小窗口了
                    //先记录当前的最小值
                    if(r-l<len){
                        len=r-l;
                        start=l;
                    }
                    char d=s[l];
                    l++;
                    if(need.count(d)){
                        if(window[d]==need[d]){
                            valid--;
                        }
                        window[d]--;
                    }
                }
            }
            if(len==INT_MAX) return "";
            else return s.substr(start,len);
    
        }
    };