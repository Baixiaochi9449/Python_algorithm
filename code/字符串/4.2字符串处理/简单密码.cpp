#include <iostream>
#include <cstdio>
#include <string>
using namespace std;

int main(){
    string str_begin;
    while(getline(cin,str_begin)){
        if (str_begin=="ENDOFINPUT"){
            break;
        }
        else{
            string str;
            string str_end;
            getline(cin,str);
            for (int i=0;i<str.size();i++){
                if ('A'<=str[i] && str[i]<='E'){
                    str[i]+=21;
                }
                else if ('F'<=str[i] && str[i]<='Z'){
                    str[i]-=5;
                }
            }
            getline(cin,str_end);
            cout << str << '\n';
        }
    }
    return 0;
}