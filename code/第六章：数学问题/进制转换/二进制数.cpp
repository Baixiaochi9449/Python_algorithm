#include <iostream>
#include <stack>
using namespace std;

int main(){
    int n;
    while(cin >> n){
        stack<int> number;
        while(n>0){
            int temp=n%2;
            number.push(temp);
            n/=2;
        }
        while(!number.empty()){
            cout << number.top();
            number.pop();
        }
        cout << endl;
    }
    return 0;
}
