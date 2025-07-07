#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(){
    vector<string> vec;
    string curstr="";
    char c;
    while(cin.get(c)){
        if(c=='\n') break;
        if(c==' '){
            vec.push_back(curstr);
            curstr="";
        }
        else curstr+=c;
    }
    vec.push_back(curstr);
    string tar;
    cin >> tar;
    string substitute;
    cin >> substitute;
    for(int i=0;i<vec.size();i++){
        if(vec[i]==tar) vec[i]=substitute;
    }
    for(int i=0;i<vec.size()+1;i++){
        cout << vec[i] << ' ';
    }
}