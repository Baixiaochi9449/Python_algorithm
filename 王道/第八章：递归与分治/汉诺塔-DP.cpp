#include <iostream>
#include <vector>
using namespace std;



int main(){
    int n;
    while(cin >> n){
        vector<int> count(n+1);
        count[0]=0;
        count[1]=2;
        for(int i=2;i<=n;i++){
            count[i]=3*count[i-1]+2;
        }
        cout << count[n] << endl;
    }
    return 0;
}