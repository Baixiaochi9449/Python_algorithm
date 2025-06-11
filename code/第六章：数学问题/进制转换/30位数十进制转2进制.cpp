#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main(){
    string str;
    while(cin >> str){
        stack<int> result;
        for(int i=0;i<str.size();){   //只要有一个0出现，就i++，这个是最终需要几轮，出现一个0，就是一轮，所以总共最多三轮,也不是，如果没出现0，就再算一遍，所以不知道最后几轮for循环，所以要记住这个循环
            int remainder=0;
            int quotient = 0;
            for(int j=i;j<str.size();j++){   //j只需要从i的地方开始除就好了
                int r=(10*remainder+(str[j]-'0'))%2;
                str[j]=(10*remainder+(str[j]-'0')) /2 +'0';
                remainder=r;
            }
            result.push(remainder);
            if (str[i]=='0') i++;     //一定注意细节，这里需要等于字符串
        }
        while(!result.empty()){
            cout << result.top();
            result.pop();
        }
        cout << endl;
    }
    return 0;
}