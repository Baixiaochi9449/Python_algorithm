#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main(){
    int M,N;
    while(cin >> M >> N){
        cin.ignore();  // 清除换行符
        string X;
        getline(cin,X);
        int sum=0;
        int fraction=1;
        stack<int> number;
        for(int i=X.size()-1;i>=0;i--){
            sum+=(X[i]-'0')*fraction;
            fraction*=M;
        }
        while(sum>0){
            int temp=sum%N;
            number.push(temp);
            sum/=N;
        }
        while(!number.empty()){
            cout << number.top();
            number.pop();
        }
        cout << endl;
    }

}