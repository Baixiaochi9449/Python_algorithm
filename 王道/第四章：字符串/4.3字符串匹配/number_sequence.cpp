#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

vector<int> get_next(const vector<int>& pattern){
    int m=pattern.size();
    vector<int> next(m, 0);
    int j=0;
    for(int i =1;i<m;i++){
        j=next[i-1];
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

int run_KMP(const vector<int>& next, const vector<int>& text, const vector<int>& pattern){
    int n=text.size();
    int m=pattern.size();
    int j=0;
    for (int i=0;i<n;i++){
        while(j>0 && text[i]!=pattern[j]){
            j=next[j-1];
        }
        if (text[i]==pattern[j]){
            j++;
        }
        if (j==m){
            return i-j+2;  
        }
    }
    return -1;  //没有找到匹配的字符串
}



int main(){
    int T=0;
    cin >> T;
    while(T--){
        int n=0,m=0;
        cin >> n >> m;

        vector<int> text(n), pattern(m);
        for (int i=0;i<n;i++){
            cin >> text[i];
        }
        for (int i=0;i<m;i++){
            cin >> pattern[i];
        }

        vector<int> next = get_next(pattern);
        int idx = run_KMP(next, text, pattern);
        cout << idx << endl;
    }
    return 0;
}