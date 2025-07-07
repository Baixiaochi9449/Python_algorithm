#include <iostream>
#include <string>
using namespace std;

int main(){
    string str;
    while(cin >> str){
        int n=str.size();
        int sum=0;
        for(int i=0;i<str.size();i++){
            int a=str[i]-'0';
            sum+=a*((1 << n )-1);
            n--;
        }
        cout << sum <<endl;
    }
}