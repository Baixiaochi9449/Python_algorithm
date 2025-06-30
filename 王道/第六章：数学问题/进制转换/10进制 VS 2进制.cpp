#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string NtoM(const int& N,const int& M,const string& number){
    string str=number;
    string result="";  //倒序的
    for(int i=0;i<str.size();){
        int remainder=0;
        for(int j=i;j<str.size();j++){
            int r=(N*remainder+(str[j]-'0'))%M;
            str[j]=(N*remainder+(str[j]-'0'))/M +'0';
            remainder=r;
        }
        result+=remainder+'0';
        if(str[i]=='0') i++;
    }
    return result;
}

int main(){
    string number;
    while(cin >> number){
        string num1=NtoM(10,2,number);
        string num2=NtoM(2,10,num1);  //翻转的
        reverse(num2.begin(),num2.end());
        int i=0;
        for(i=0;i<num2.size();i++){
            if(num2[i]!='0') break;
        }
        cout << num2.substr(i);
    }
}