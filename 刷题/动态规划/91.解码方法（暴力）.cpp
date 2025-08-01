//回溯：先回溯来一遍。 每次选择一个字符或2个字符
//几种就是dp
//在 backtracking 函数中，你使用了 for(int i=index;i<s.size();i++)，这会导致重复处理同一位置的字符，从而产生错误的结果。回溯的目的是尝试不同的选择路径，而不是遍历所有可能的起始位置
class Solution {
    private:
        int result=0;
        void backtracking(string s,int index){
            //当index=s.size()时候收集结果
            if(index==s.size()) {
                result++;
                return ;
            }
            if(s[index]=='0') return ;
            //如果是for循环，说明每一层有多种选择，这个每一层只有2种选择。
            //只选一个
            if(index+1<=s.size()) backtracking(s,index+1);
            //选2个
            if(index+2<=s.size()){
                int sum=(s[index]-'0')*10 +(s[index+1]-'0');
                if(sum<=26) backtracking(s,index+2);
            }
        }
    public:
        int numDecodings(string s) {
            backtracking(s,0);
            return result;
        }
    };