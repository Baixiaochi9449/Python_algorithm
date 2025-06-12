#include <iostream>
using namespace std;

long long compute(int n){
    if(n==1){
        return 2;
    }
    else{
        return 3*compute(n-1)+2;
    }
}

int main(){
    int n;
    while(cin >> n){
        cout << compute(n) << endl;
    }
    return 0;
}