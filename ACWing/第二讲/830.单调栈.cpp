//只会暴力
//从左往右，如果栈为空，输出-1，并把当前值压入栈。
//如果栈为空，直接压进去，输出-1。如果栈不为空，如果top<cur 输出top 并把cur压进去。  如果top>cur  ,一直反复弹出top,知道找到一个数比cur小，输出，如果为空了，就输出-1，并压入栈
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> arr(n);
    stack<int> sta;
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }
    for(int i=0;i<n;i++){
        while(!sta.empty() && sta.top()>=arr[i]){
            sta.pop();
        }
        if(sta.empty()) cout << -1 << ' ';
        else cout << sta.top() << ' ';                
          
        sta.push(arr[i]);
    }
    return 0;
}