class Solution {
    public:
        vector<int> findAnagrams(string s, string p) {
            vector<int> result;
            unordered_map<char,int> need,windows;
            for(char c : p) need[c]++;
    
            int left=0,right=0;
            int valid=0;
            while(right<s.size()){
                char c =s[right];
                right++;
                if(need.count(c)){
                    windows[c]++;
                    if(windows[c]==need[c]){
                        valid++;
                    }
                }
    
                while(right-left>=p.size()){  //当长度==p.size()的时候
                    if(valid==need.size()){
                        result.push_back(left);
                    }
                    char c = s[left];
                    left++;
                    if(need.count(c)){
                        if(need[c]==windows[c]) valid--;
                        windows[c]--;
                    }
                }
            }
            return result;
        }
    };