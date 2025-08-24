//以i为中心，和以i+1为中心， 各自求出一个回文序列的长度
#include <iostream>
#include <string>
#include <cstdio>
using namespace std;

int get_length(int l,int r,string s){
    while(l>=0 && r<s.size() && s[l]==s[r]){
        l--;
        r++;
    }
    return r-l-1;
}

int main(){
    string s;
    getline(cin,s);
    int n=s.size();
    int res=0;
    for(int i=0;i<n;i++){
        int res1=get_length(i,i,s);
        res=max(res,res1);
        if(i<n-1){
            int res2=get_length(i,i+1,s);
            res=max(res,res2);
        }
    }
    cout << res << endl;
    return 0;
}