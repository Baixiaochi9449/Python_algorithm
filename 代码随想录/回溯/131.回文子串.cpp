class Solution {
private:
    vector<vector<string>> result;
    vector<string> path;
    bool ispalindrome(string s,int startindex,int i){
        int pre=startindex;
        int nex=i;
        while(pre<nex){
            if(s[pre]==s[nex]){
                pre++;;
                nex--;
            }
            else{
                return false;
            }
        }
        return true;
    }
    void backtracking(string s,int startindex){
        if(startindex==s.size()){
            result.push_back(path);
            return ;
        }
        for(int i=startindex;i<s.size();i++){
            if(ispalindrome(s,startindex,i)){
                path.push_back(s.substr(startindex,i-startindex+1));
            }
            else{
                continue;
            }
            backtracking(s,i+1);
            path.pop_back();
        }
        return ;
    }
public:
    vector<vector<string>> partition(string s) {
        backtracking(s,0);
        return result;
    }
};