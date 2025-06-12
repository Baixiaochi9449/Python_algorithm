#include <iostream>
#include <cmath>
using namespace std;

int main(){
    int n;
    while(cin >> n){
        if (n==0 || n==1 || n<0){
            cout << "no"<<endl;
        }
        else if (n==2 ||n==3){
            cout << "yes" <<endl;
        }
        else{
            bool isprime=true;
            for (int i=2;i<=sqrt(n);i++){
                if (n%i==0){
                    cout << "no" << endl;
                    isprime=false;
                    break;
                }
            }
            if(isprime){
                cout << "yes"<< endl;
            }
        }
    }
    return 0;
}