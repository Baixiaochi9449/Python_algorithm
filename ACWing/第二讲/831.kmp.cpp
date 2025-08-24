//都是围绕着模式串pattern来的
#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<int> get_next(int n,string pattern){
    vector<int> next(n,0);
    int j=0;
    for(int i=1;i<n;i++){
        while(j>0 && pattern[j]!=pattern[i]){
            j=next[j-1];
        }
        if(pattern[j]==pattern[i]) j++;
        next[i]=j;
    }
    return next;
}


int main(){
    int n;
    string pattern;
    cin >> n >> pattern;
    int m;
    string s;
    cin >> m >> s;
    vector<int> next=get_next(n,pattern);
    
    int j=0;
    for(int i=0;i<m;i++){
        while(j>0 && pattern[j]!=s[i]){
            j=next[j-1];
        }
        if(pattern[j]==s[i]){
            j++;
        }
        if(j==n){ //完全匹配了
            cout << i-n+1 << ' ';
            j=next[j-1];
        }
    }
    return 0;
}