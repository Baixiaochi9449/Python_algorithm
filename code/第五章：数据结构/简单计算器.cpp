#include <iostream>
#include <stack>
#include <string>
#include <iomanip>
#include <cctype>
using namespace std;


//1、设置优先级
int priority(const char& op){
    if(op=='(') return 0;
    if(op=='+' || op=='-') return 1;
    if(op=='*' || op=='/') return 2;
}

//2.设置符号的运算过程
int run_op(const char& op,const int& num1,const int& num2){
    switch(op){
        case '+': return num1+num2;
        case '-': return num1-num2;
        case '*': return num1*num2;
        case '/': 
            if(num2==0){
                cout << "Error: division by zero" << endl;
                return 0;
            }
            else{
                return num1/num2;
            }
    }
}

int main(){
    string str;
    while(getline(cin,str)){
        if(str=="0") break;
        else{
            stack<double> number;
            stack<char> op;
            for(int i=0;i<str.size(); ){   //不在这里写i++,   i在哪里变，后面有安排
                if(isspace(str[i])){     //空字符串
                    i++;
                    continue;
                }
                if(isdigit(str[i])){    //数字
                    double num=0;
                    while(i<str.size() && isdigit(str[i])){
                        num=num*10 +(str[i]-'0');
                        i++;
                    }
                    if(i<str.size() && str[i]=='.'){
                        i++;
                        double fraction=0.1;
                        while(i<str.size() && isdigit(str[i])){
                            num+=fraction*(str[i]-'0');
                            fraction*=0.1;
                            i++;
                        }
                    }
                    number.push(num);
                }
                else if(str[i]=='('){
                    op.push(str[i]);
                    i++;
                }
                else if(str[i]==')'){  //把括号里面的内容全都算了
                    while(!op.empty() && op.top()!='('){
                        double num2=number.top();
                        number.pop();
                        double num1=number.top();
                        number.pop();
                        char oper=op.top();
                        op.top();
                        number.push(run_op(oper,num1,num2));
                    }
                    op.pop();
                    i++;
                }
                else{
                    while(!op.empty() && priority(str[i])<priority(op.top())){
                        char oper=op.top();
                        op.pop();
                        double num2=number.top();
                        number.pop();
                        double num1=number.top();
                        number.pop();
                        number.push(run_op(oper,num1,num2));
                    }
                    op.push(str[i]);
                    i++;
                }

            }
            while(!op.empty()) {
                char oper = op.top();
                op.pop();
                double num2 = number.top();
                number.pop();
                double num1 = number.top();
                number.pop();
                number.push(run_op(oper, num1, num2));
            }    //把剩下的运算符都算完
            if(!number.empty()) {
            // 设置输出格式，保留2位小数
                cout << fixed << setprecision(2) << number.top() << endl;
            }
        }
    }
    return 0;
}

