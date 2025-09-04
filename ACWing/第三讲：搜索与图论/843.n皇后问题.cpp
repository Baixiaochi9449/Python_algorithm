//定义一个二维数组，初始化都是.  vector<vector<string>> result;  vector<string> path(4,string('.'))
//path用来存储每一行
//bool isvalid用来判断是否合法
//依然每一层从i=0开始，然后判断是否合法，有回溯的过程
#include <iostream>
#include <vector>
#include <string>
using namespace std;



int n;
vector<string> path;
string str;
bool isvalid(int row,int col){
    //同一列
    for(int i=0;i<row;i++){
        if(path[i][col]=='Q') return false;
    }
    //右上角
    for (int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++){
        if(path[i][j]=='Q') return false;
    }
    //不是嵌套循环
    for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--){
        if(path[i][j]=='Q') return false;
    }
    return true;
}

void backtracking(int row){
    if(row==n){
        for(int i=0;i<n;i++){
            cout << path[i] << endl;
        }
        cout << endl;
        return ;
    }
    for(int i=0;i<n;i++){
        if(isvalid(row,i)){ //如果这个位置是合法的
            string temp=str;
            temp[i]='Q';
            path.push_back(temp);
            backtracking(row+1);
            path.pop_back();
        }
    }
    return ;
}

int main(){
    cin >> n;
    str="";
    str.append(n,'.');
    backtracking(0);
    return 0;
}
