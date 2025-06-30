class Solution {
private:
    vector<string> result;
    bool isvalid(string s,int startindex,int i){
        string str=s.substr(startindex,i-startindex+1);
        if(startindex>i){
            return false;
        }
        if(str.size()>1 && str[0]=='0'){
            return false;
        }
        if(str.size()==3){
            int sum=0;
            for(int i=0;i<str.size();i++){
                sum=sum*10+str[i]-'0';
            }
            if(sum>255){
                return false;
            }
        }
        if(str.size()>3){
            return false;
        }
        return true;
    }
    
    void backtracking(string s,int startindex,int pointsum){
        if(pointsum==3){
            if(isvalid(s,startindex,s.size()-1)){
                result.push_back(s);
                return ;
            }
            else{
                return ;
            }
        }
        for(int i=startindex;i<s.size();i++){
            if(isvalid(s,startindex,i)){
                s.insert(s.begin()+i+1,'.');
                pointsum+=1;
            }
            else{
                continue;
            }
            backtracking(s,i+2,pointsum);
            s.erase(s.begin()+i+1);
            pointsum-=1;
        }
    }

public:
    vector<string> restoreIpAddresses(string s) {
        result.clear();
        backtracking(s,0,0);
        return result;
    }
};