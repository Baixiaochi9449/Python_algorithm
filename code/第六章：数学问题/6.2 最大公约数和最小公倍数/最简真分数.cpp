#include <iostream>
#include <vector>
using namespace std;

int GCD(int a, int b){
    if(b==0) return a;
    else return GCD(b,a%b);
}

int main(){
    int n=0;
    while(cin >> n){
        if (n==0){
            break;
        }
        vector<int> num(n);
        for(int i=0;i<n;i++){
            cin >>num[i];
        }
        int count=0;
        for(int i=0;i<n-1;i++){
            for(int j=i+1;j<n;j++){
                if(GCD(num[i],num[j])==1){
                    count++;
                }
            }
        }
        cout << count << endl;
    }
    return 0;
}