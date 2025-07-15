//当前字符串s。 记录当前.的数量，，如果.的数量=3就判断是否有效，有效就加入到result,然后回溯，删除当前的.
//判断是否有效
//每次判断一下当前截取的数字是否有效
class Solution {
private:
    bool isvalid(string s,int index,int i){
        string str=s.substr(index,i-index+1);
        if(index>i) return false;
        if(str.size()>1 && str[0]=='0') return false;
        if(str.size()==3){
            int sum=0;
            for(int i=0;i<str.size();i++){  //直接可以这么写，因为一开始sum=0
                sum=sum*10+str[i]-'0';
            }
            if(sum>255) return false;
        }
        if(str.size()>3) return false;

        return true;
    }
    vector<string> result;
    void backtracking(string s,int num,int index){
        if(num==3){
            if(isvalid(s,index,s.size()-1)){  //判断最后一个
                result.push_back(s);
            }
            return ;
        }
        for(int i=index;i<s.size();i++){  //这里的i应该是什么
            if(isvalid(s,index,i)){
                s.insert(s.begin()+i+1,'.');
                num++;
            }
            else{
                continue;
            }
            backtracking(s,num,i+2);
            num--;
            s.erase(s.begin()+i+1);  //删除索引为i的元素
        } 
        return ;  
    }
public:
    vector<string> restoreIpAddresses(string s) {
        result.clear();
        backtracking(s,0,0);
        return result;
    }
};