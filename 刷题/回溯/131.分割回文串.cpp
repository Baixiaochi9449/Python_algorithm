//要把所有的存起来，回溯。 到最后一个的时候，收集结果。 放入每个path的时候要判断是否回文

class Solution {
private:
    vector<vector<string>> result;
    vector<string> path;
    void backtracking(string s ,int index){
        if(index==s.size()){
            result.push_back(path);
            return ;
        }
        for(int i=1;i+index<=s.size();i++){
            string sub=s.substr(index,i);
            if(palindrome(sub)){
                path.push_back(sub);
                backtracking(s,index+i);
                path.pop_back();
            }
        }
        return ;
    }
    bool palindrome(string str){
        if(str.size()==1) return true;
        int i=0,j=str.size()-1;
        while(i<=j){
            if(str[i]==str[j]) {
                i++;
                j--;
            }
            else return false;
        }
        return true;
    }
public:
    vector<vector<string>> partition(string s) {
        result.clear();
        path.clear();
        backtracking(s,0);
        return result;
    }
};