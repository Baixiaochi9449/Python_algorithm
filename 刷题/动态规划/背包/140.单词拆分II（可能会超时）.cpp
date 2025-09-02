//回溯
class Solution {
private:
    vector<string> res;
    string path="";
    void backtracking(string s,unordered_set<string>& memo,int index){
        if(index==s.size()){
            string temp=path;
            temp.pop_back(); //删除单个字符
            res.push_back(temp);
            return ;
        }
        for(int i=index;i<s.size();i++){
            string str=s.substr(index,i-index+1); //左闭右闭
            int oldsize=path.size();
            if(memo.find(str)!=memo.end()){
                path+=(str+" ");
                backtracking(s,memo,i+1);
                path.resize(oldsize);
            }
        }
        return ;
    }
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> memo(wordDict.begin(),wordDict.end());
        res.clear();
        backtracking(s,memo,0);
        return res;
    }
};
