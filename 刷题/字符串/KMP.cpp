#include<iostream>
#include<string>
#include<vector>

using namespace std;
int MAX = 10000;
vector<int> Next(MAX);

void getNext(string pattern) {
    int j = 0;
    Next[0] = 0; //1/
    for (int i = 1; i < pattern.size(); i++) {
        if (pattern[i] != pattern[j] && j > 0) { //2
            j = Next[j - 1];
        }
        if (pattern[i] == pattern[j]) { //3
            j++;
        }
        Next[i] = j; //4
    }
}

bool run_KMP(string text, string pattern) {
    int i = 0, j = 0;
    for(int i=0;i<text.size();i++){
        //不想等
        while(j>0 && text[i]!=pattern[j]){
            j=Next[j-1];
        }
        //相等
        if(text[i]==pattern[j]){
            j++;
        }
        if(j==pattern.size()) return true;
    }
    return false;
}

int main() {
    string text, pattern;
    while (cin >> text >> pattern) {
        //如何初始化next？
        //首先建立next表
        getNext(pattern);
        if(run_KMP(text,pattern)) cout << "true" << endl;
        else{
            cout << "false" << endl;
        }
    }
    return 0;
}