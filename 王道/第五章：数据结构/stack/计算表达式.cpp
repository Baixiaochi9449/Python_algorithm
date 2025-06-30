#include <iostream>
#include <string>
#include <stack>
#include <cctype>
using namespace std;

int priority(const char& oper){
    if (oper=='#') return 0;
    if (oper=='$') return 1;
    if(oper=='+' || oper=='-') return 2;
    if(oper=='*' || oper=='/') return 3;
    return -1;
}

double operation(const char& oper,const double& num1,const double& num2){
    switch(oper){
        case '+': return num1+num2;
        case '-': return num1-num2;
        case '*': return num1*num2;
        case '/': return num1/num2;  
    }
    return -1;
}

int main(){
    string str;
    while(getline(cin,str)){
        stack<double> number;
        stack<char> op;
        str+='$';
        op.push('#');
        if(str=="0"){
            break;
        }
        else{
            int idx=0;
            while(idx<str.size()){
                if(isdigit(str[idx])){
                    double num=0;
                    while(isdigit(str[idx])){
                        num=num*10 + (str[idx]-'0');
                        idx++;
                    }
                    number.push(num);
                }
                else{
                    while (priority(op.top()) >= priority(str[idx])) {  // 修改为while循环
                        char oper = op.top();
                        op.pop();
                        double num2 = number.top();
                        number.pop();
                        double num1 = number.top();
                        number.pop();
                        number.push(operation(oper, num1, num2));
                    }
                    op.push(str[idx]);
                    idx++;  
                }
            }
            cout << number.top() << endl;
        }
    }
    return 0;
}