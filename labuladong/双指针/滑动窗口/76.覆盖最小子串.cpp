class Solution {
    public:
        string minWindow(string s, string t) {
            if(s.size()<t.size()) return "";
            
            unordered_map<char,int> need,windows;
            for(int i=0;i<t.size();i++){
                char c = t[i];
                need[c]++;
            }
            int left=0,right=0;
            int valid=0;
            int begin=0,L=INT_MAX;
    
            while(right<s.size()){
                char c =s[right];
                right++;
                //更新窗口
                if(need.count(c)){
                    windows[c]++;
                    if(windows[c]==need[c]){
                        valid++;
                    }
                }
    
                while(valid==need.size()){
                    //记录长度
                    if(right-left<L){
                        L=right-left;
                        begin=left;
                    }
                    //缩小窗口
                    char c = s[left];
                    left++;
                    if(need.count(c)){
                        if(windows[c]==need[c]){
                            valid--;
                        }
                        windows[c]--;
                    }
                }
            }
            return L == INT_MAX ? "" : s.substr(begin, L);
        }
    };