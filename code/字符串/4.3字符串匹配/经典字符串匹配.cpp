/*
getnext: for i的循环，每次循环都执行next[i]=j ;  所以重点在j是什么？ 1、j的初始值，2、不相等的时候，3、相等的时候
run_KMP: for i的循环，为了最后j=m的时候能返回i-j+1; 所以也是找j? 1、不相等的时候 2、相等的时候
*/

#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
using namespace std;

vector<int> getnext(const string& pattern){
    int n=pattern.size();
    vector<int> next(n,0);
    int j=0;   //end of prefixes
    for (int i=1;i<n;i++){  //end of suffixes
        j = next[i-1];
        while(j>0 && pattern[i]!=pattern[j]){
            j=next[j-1];
        }
        if (pattern[i]==pattern[j]){
            j++;
        }
        next[i]=j;
    }
    return next;
}

int run_KMP(const vector<int>& next,const string& text,const string& pattern){
    int n=text.size();
    int m=pattern.size();
    int j=0;
    for( int i=0;i<n;i++){
        //首先找到相等的位置
        while(j>0 && text[i]!=pattern[j]){
            j=next[j-1];
        } 
        //找到了就匹配
        if (text[i]==pattern[j]){
            j++;
        }
        //如果能找到最后一步，说明全都匹配上了
        if (j==m){
            return i-j+1;
        }
        //没找到最后一步，即在这个for循环内没有return i-j+1
    }
    return -1;  //没找到匹配的字符串
}

int main(){
    string text,pattern;
    while(cin >> text >>  pattern){
        vector<int> next=getnext(pattern);
        int idx=run_KMP(next,text,pattern);
        cout << idx << endl;
    }
    return 0;
}


