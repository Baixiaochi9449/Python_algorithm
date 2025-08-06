//可以直接用一个长度为s1.size()的窗口，每次都判断窗内的是否包含
class Solution {
    public:
        bool checkInclusion(string s1, string s2) {
            if(s1.size()>s2.size()) return false;
            unordered_map<char,int> need,windows;
            for(int i=0;i<s1.size();i++){
                char c = s1[i];
                need[c]++;
            }
    
            int left=0,right=0;
            int valid=0;
            for(right=0;right<s1.size();right++){
                char c =s2[right];
                if(need.count(c)){
                    windows[c]++;
                    if(windows[c]==need[c]){
                        valid++;
                    }
                }
            }
            if(valid==need.size()) return true;
    
            //目前right指向了s1.size()的位置
            right--;  
            while(right+1<s2.size()){
                right++;
                char a =s2[right]; //要加入的
                char b =s2[left];  //要删除的
                if(need.count(a)){
                    windows[a]++;
                    if(windows[a]==need[a]){
                        valid++;
                    }
                }
                if(need.count(b)){
                    if(windows[b]==need[b]) valid--;
                    windows[b]--;
                }
                left++;
    
                if(valid==need.size()) return true;
            }
            return false;
        }
    };