#include <iostream>
#include <vector>
using namespace std;

int main(){
    int a_0,a_1,p,q,k;
    while(cin >> a_0 >> a_1 >> p >> q >>k){
        vector<int> result(k);
        result[0]=a_0;
        result[1]=a_1;
        for(int i=2;i<k;i++){
            result[i]=(p*result[i-1] + q*result[i-2])%10000;
        }
        cout << result[k-1] << endl;
    }
    return 0;
}