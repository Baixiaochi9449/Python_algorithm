#include <iostream>
#include <queue>

using namespace std;

int main(){
    int n;
    while(cin >>n){
        priority_queue<int,vector<int>,greater<int>> Q;
        for(int i=0;i<n;i++){
            int a;
            cin >>a;
            Q.push(a);
        }
        int k;
        cin >>k;
        int i=0;
        while(i!=k-1){
            int fi=Q.top();
            Q.pop();
            i++;
            int ne=Q.top();
            while(ne==fi){
                Q.pop();
                ne=Q.top();
            }
        }
        cout << Q.top() <<endl;
    }
    return 0;
}