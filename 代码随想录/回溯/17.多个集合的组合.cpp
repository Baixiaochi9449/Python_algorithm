class Solution {
private:
    vector<string> MAPPING ={ "", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    string s;
    vector<string> result;
    void backtracking(string digits,int index){
        if(index==digits.size()){
            result.push_back(s);
            return ;
        }
        int digit=digits[index]-'0';   //获取“234” 中的 2
        string letter=MAPPING[digit];    //获取2对应的字符
        for(int i=0;i<letter.size();i++){
            s.push_back(letter[i]);
            backtracking(digits,index+1);
            s.pop_back();
        }
    }

public:
    vector<string> letterCombinations(string digits) {
        if(digits==""){
            return {};
        }
        else{
            backtracking(digits,0);
            return result;
        }
    }
};