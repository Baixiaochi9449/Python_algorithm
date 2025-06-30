#include <iostream>
#include <queue>

using namespace std;

int main(){
    int n;
    while(cin >>n){
        if(n==0){
            break;
        }
        priority_queue<int,vector<int>,greater<int>> Q;
        for(int i=0;i<n;i++){
            int a;
            cin >>a;
            Q.push(a);
        }
        int sum=0;
        while(Q.size()>1){
            int a,b;
            a=Q.top();
            Q.pop();
            b=Q.top();
            Q.pop();
            sum=sum+a+b;
            Q.push(a+b);
        }
        cout<< sum<<endl;
    }
    return 0;
}