#include <iostream>
using namespace std;

int countnode(int m,int n){
    if(m>n){
        return 0;
    }
    else{
        return 1+countnode(2*m,n) +countnode(2*m+1,n);
    }
}

int main(){
    int m,n;
    while(cin >> m >> n){
        if(m==0){
            break;
        }
        else{
            int result = countnode(m,n);
            cout<< result <<endl;
        }
    }
    return 0;
}
