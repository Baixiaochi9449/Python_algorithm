#include <iostream>

using namespace std;

int FastExponent(int a,int b,int mod){
    int sum=1;
    while(b!=0){
        if(b%2==1){   //当前位 为1
            sum*=a;
            sum%=mod;
        }
        b/=2;
        a*=a;
        a%=mod;
    }
    return sum;
}

int main(){
    int a,b;
    while(cin >> a>> b){
        int sum=FastExponent(a,b,1000);
        cout << sum <<endl;
    }
    return 0;
}