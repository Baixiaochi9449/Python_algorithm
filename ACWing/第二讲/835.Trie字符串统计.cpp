//维护一个unordered_map
#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

int main(){
    int N;
    cin >>N;
    unordered_map<string,int> memo;
    while(N--){
        char op;
        string s;
        cin >> op >> s;
        if(op=='I'){
            memo[s]++;
        }
        else{
            if(memo.count(s)){
                cout << memo[s] << endl;
            }
            else cout<< 0 << endl;
        }
    }
    return 0;
}