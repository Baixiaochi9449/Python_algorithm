class Solution {
public:
    string longestPrefix(string s) {
        //next数组求的是什么，求的是前面的字符串，最长前后缀的长度
        //所以直接算next数组就可以
        int n=s.size();
        vector<int> next(n,0);
        int j=0;
        for(int i=1;i<n;i++){
            while(j>0 && s[i]!=s[j]){
                j=next[j-1];
            }
            if(s[i]==s[j]) j++;
            next[i]=j;
        }
        //最后一个字符串的最长前后缀长度
        int len=next[n-1];
        string res=s.substr(0,len);
        return res;
    }
};
