//找数组中最小的2个数，合并，放到数组中。再找数组中最小的2个数，合并，放到数组中。直到数组中只有一个数
//用优先级队列？
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main(){
    int n;
    cin >> n;
    priority_queue<int,vector<int>, greater<int> > que;
    while(n--){
        int a;
        cin >>a;
        que.push(a);        
    }

    int res=0;
    while(!que.empty()){
        int a=que.top();
        que.pop();
        if(que.empty()) break;
        int b=que.top();
        que.pop();
        res+=(a+b);
        que.push(a+b);
    }
    cout << res << endl;
    return 0;
}