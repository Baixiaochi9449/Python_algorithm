#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

vector<int> prime;
vector<bool> isprime(sqrt(1e9));

void initial(const int& n){
    for(int i=0;i<n;i++){
        if (i<2){
            isprime[i]=false;
        }
        else{
            isprime[i]=true;
        }
    }

    for(int i=2;i<n;i++){
        if(!isprime[i]){
            continue;
        }
        prime.push_back(i);
        for(int j=i*i;j<n;j+=i){
            isprime[j]=false;
        }
    }
    return ;
}

int main(){
    int n;
    while(cin >> n){
        initial(sqrt(n)+1);
        int count=0;
        for(int i=0;i<prime.size() && n>0 ;i++){
            while(n>0 && n%prime[i]==0){
                count++;
                n/=prime[i];
            }
        }
        if(n>1){         //n最多存在一个 大于sqrt(n)的质因数，在先前的
            count++;     //没大明白是什么意思？？？？
        }
        cout << count << endl;
    }
    return 0;
}