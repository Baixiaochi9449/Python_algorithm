//大数相乘 ，不要用整数乘法了
//法一： 6与123相乘，保存到一个数组里。  5与123相乘，保存到一个数组里
//滚动数组，坐标=i+j+1
class Solution {
public:
    string multiply(string num1, string num2) {
        if(num1=="0" || num2=="0") return "0";
        int n=num1.size();
        int m=num2.size();
        vector<int> result(n+m,0);
        for(int i=n-1;i>=0;i--){
            for(int j=m-1;j>=0;j--){
                result[i+j+1]+=(num1[i]-'0')*(num2[j]-'0');
            }
        }
        for(int i=result.size()-1;i>0;i--){
            result[i-1]+=result[i]/10;
            result[i]=result[i]%10;
        }
        string res="";
        if(result[0]==0){
            for(int i=1;i<result.size();i++){
                res+=(result[i]+'0');
            }
        }
        else{
            for(int i=0;i<result.size();i++){
                res+=(result[i]+'0');
            }
        }
        return res;
    }
};