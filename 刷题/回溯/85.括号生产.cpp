//回溯
//记录右括号的数量，k ,如果k==n 收集结果
//记录左括号的数量，l,if(l>k&& l<=n) 放左括号， if(l>k,放右括号)  每层2种选择 
class Solution {
private:
    vector<string> result;
    string path="";
    void backtracking(int n,int l,int r){
        if(r==n && l==n){
            result.push_back(path);
            return ;
        }
        if(l<=n){
            path=path+"(";
            l++;
            backtracking(n,l,r);
            l--;
            path.pop_back();
        }
        if(r<l && l<=n){
            path+=")";
            r++;
            backtracking(n,l,r);
            r--;
            path.pop_back();
        }
        return ;
    }
public:
    vector<string> generateParenthesis(int n) {
        result.clear();
        backtracking(n,0,0);
        return result;
    }
};