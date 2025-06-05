#include <iostream>
#include <string>
#include <cstdio>
using namespace std;

int main(){
    string st1;
    string st2;
    while(cin >> st1 >> st2){
        int sum=0;
        for (int i=0;i<st1.size();i++){
            for (int j=0;j<st2.size();j++){
                sum+=(st1[i]- '0')*(st2[j]- '0');
            }
        }
        cout<<sum << '\n';
        

    }
}