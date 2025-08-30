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
