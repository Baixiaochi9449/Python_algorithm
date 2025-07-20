#include <iostream>
#include <string>
#include <vector>
using namespace std;

int MAX=10;

vector<int> build_next(string pattern){
    vector<int> Next(pattern.size(),0);
    int j=0;
    for(int i=0;i<pattern.size();i++){
        while(j>0 && pattern[i]!=pattern[j]){
            j=Next[j-1];
        }
        if(pattern[i]==pattern[j]) j++;
        Next[i]=j;
    }
    return Next;
}

int run_KMP(string pattern,string text){
    vector<int> Next= build_next(pattern);
    int result=0;
    int j=0;
    for(int i=0;i<text.size();){
        while(j>0 && text[i]!=pattern[j]){
            j=Next[j-1];
        }
        if(text[i]==pattern[j]){
            j++;
            i++;
        }
        else if(j==0) i++; //完全不匹配时，i++
        
        if(j==pattern.size()){ //此时已经完全匹配
            result++; 
            j=Next[j-1]; //把j回退到初始位置？
        }
    }
    return result;
}

int main(){
    int T;
    cin >> T;
    while(T--){
        string pattern;
        string text;
        cin >> pattern >> text;
        cout << run_KMP(pattern,text) << endl;
    }
}