class Solution {
    public:
        vector<int> findAnagrams(string s, string p) {
            //need  window valid
            //相等的时候，r++,不满足的时候直到找到一个满足的，让l=r r++
            //先不考虑多出来的情况
            //使用固定的窗口，push不push只看valid 。 所以就是在r-l==p.size()的时候缩小窗口
            unordered_map<char,int> need,window;
            vector<int> res;
            for(char c : p){
                need[c]++;
            }
            int valid=0;
            int l=0,r=0;
            while(r<s.size()){
                char c=s[r];
                r++;
                if(need.count(c)){
                    window[c]++;
                    if(window[c]==need[c]){
                        valid++;
                    }
                }
                while(r-l>=p.size()){
                    if(valid==need.size()){
                        res.push_back(l);
                    }
                    char d=s[l];
                    l++;
                    if(need.count(d)){
                        if(need[d]==window[d]){
                            valid--;
                        }
                        window[d]--;
                    }
                }
            }
            return res;
        }
    };