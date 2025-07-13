//左括号：压入栈  右括号，从栈顶弹出，是否匹配
class Solution {
public:
    bool isValid(string s) {
        unordered_map<char,char> pair{
            {')','('},
            {']','['},
            {'}','{'}
        };
        stack<char> sta;
       
        for(int i=0;i<s.size();i++){
            if(!pair.count(s[i])){  //左括号
                sta.push(s[i]);
            }
            else{  //右括号
                if(sta.empty()) return false;
                char cur=sta.top();
                sta.pop();
                if(pair[s[i]]!=cur) return false;
            }
        }
        if(!sta.empty()) return false;
        return true;
    }
};