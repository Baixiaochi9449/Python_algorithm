//用优先级队列
#include <iostream>
#include <cstdio>
#include <queue>
using namespace std;

int main(){
    int n,m;
    cin >> n >> m;
    priority_queue<int,vector<int>,greater<int>> que;
    while(n--){
        int a;
        cin >>a;
        que.push(a);
    }
    while(m--){
        cout << que.top() << ' ';
        que.pop();
    }
    return 0;
}