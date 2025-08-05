//暴力截取每一段，判断是否回文
//dp 分很多情况
//dp[i][j] i到j的范围内是否是回文的   if(==)   中间有<=1个元素 true  else dp[i][j]=dp[i+1][j-1]
//从下到上，从左到右
//初始化i i的位置都是回文的。   
//结果 ；只要是回文的，result=max(result,j-i+1)  curstr=substr(i,j-i+1)
class Solution {
public:
    string palindrome(string s,int l ,int r){
        while(l>=0 && r<s.size() && s[l]==s[r]){
            l--;
            r++;
        }
        return s.substr(l+1,r-l-1);
    }
    string longestPalindrome(string s) {
        //不用dp,找以i为中心的回文子串，和找i和i+1为中心的回文子串
        if(s.size()<=1) return s;
        string res="";
        for(int i=0;i<s.size();i++){
            string s1=palindrome(s,i,i);
            string s2=palindrome(s,i,i+1);
            res = res.size()>s1.size()? res:s1;
            res = res.size()>s2.size()? res:s2;
        }
        return res;
    }
};