//时间复杂度太高，所以用素数筛选法
#include <iostream>
#include <vector>
using namespace std;

// const int N=1e6+10;

int main(){

    int n;
    cin >> n;
    
    vector<bool> isprime(n+1,true);
    isprime[0]=false;
    isprime[1]=false;
    isprime[2]=true;
    for(int i=2;i<n+1;i++){
        if(isprime[i]){
            for(int j=i*i;j<n+1;j+=i){
                isprime[j]=false;
            }
        }
    }
    int res=0;
    for(int i=1;i<=n;i++){
        if(isprime[i]) res++;
    }
    cout << res << endl;
    return 0;
}