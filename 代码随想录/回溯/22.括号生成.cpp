//如果左括号数量不大于 n，我们可以放一个左括号。如果右括号数量小于左括号的数量，我们可以放一个右括号。
//这里的层间遍历不是for循环了，而是就2种情况， 选（ 还是 ） 
//终止条件：右括号数量=max
//参数：open, close ,max 
class Solution {
private:
    vector<string> result;
    string path;
    void backtracking(int open,int close,int max){
        if(close==max){
            result.push_back(path);
        }
        //就2种情况 在层间
        if(open<max){
            path.push_back('(');
            open++;
            backtracking(open,close,max);
            open--;
            path.pop_back();
        }
        if(close < open){
            path.push_back(')');
            close++;
            backtracking(open,close,max);
            close--;
            path.pop_back();
        }
    }
public:
    vector<string> generateParenthesis(int n) {
        result.clear();
        backtracking(0,0,n);
        return result;
    }
};