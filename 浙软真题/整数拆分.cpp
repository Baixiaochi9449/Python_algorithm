//整数分解 两部分之和的平方=整数
//先把两边分开
//int变为字符串to_string  字符串变为int (stoi)
#include <iostream>
#include <string>
using namespace std;

int main(){
    int n;
    cin >> n;
    string num=to_string(n); //变为字符串
    //开始分组判断  
    for(int i=1;i<num.size();i++){  
        string str1=num.substr(0,i); //从0开始，截取后面的i个字符
        string str2=num.substr(i); //从i开始截取到最后
        int num1=stoi(str1);
        int num2=stoi(str2);
        int sum=num1+num2;
        if(sum*sum==n){
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout << "No" << endl;
    return 0;
}