#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
using namespace std;

int main(){
    string object;
    vector <int> number(128);
    while(getline(cin,object)){
        if (object=="#"){
            break;
        }
        else{
            string str;
            getline(cin,str);
            for (int i=0;i<str.size();i++){
                number[str[i]]++;
            }
        }
        for (int j=0;j<object.size();j++){
            cout << object[j] << ' ' << number[object[j]] << '\n'; 
        }
        number.assign(128, 0);
    }
}