
class Solution {
private:
    vector<string> result;
    void backtracking(string num,int target,string curexpr,int starindex,long curresult,long mul){
        if(starindex==num.size()){
            if(curresult==target) result.push_back(curexpr);
            return ;
        }

        for(int i=starindex;i<num.size();i++){
            if (i != starindex && num[starindex] == '0') {   //如果start开始的位置是0，就直接跳过，不截取这样的字符串
                break;
            }
            string sub=num.substr(starindex,i-starindex+1);
            long val=stol(sub);

            if(starindex==0){  //记住是初始位置为0 ，而不是 仅i==0
                backtracking(num,target,curexpr+sub,i+1,val,val);
            }
            else{
                backtracking(num,target,curexpr+"+"+sub,i+1,curresult+val,val);
                backtracking(num,target,curexpr+"-"+sub,i+1,curresult-val,-val);
                backtracking(num,target,curexpr+"*"+sub,i+1,curresult-mul+mul*val,mul*val);
            }
        }
    }
 
public:
    vector<string> addOperators(string num, int target) {
        result.clear();
        backtracking(num,target,"",0,0,0);
        return result;
    }
};
