#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
//如何表示M的i次方
int chartoint(char x){
    if(x>='0' && x<='9'){
        return x-'0';
    }
    else{
        return x-'A'+10;
    }
}
int main(){
    string str;
    while(cin >> str){
        string num=str.substr(2);
        int sum=0;
        int M=16;
        for(int i=0;i<num.size();i++){
            sum=sum*M+chartoint(num[i]);
        }
        cout << sum <<endl;
    }
}