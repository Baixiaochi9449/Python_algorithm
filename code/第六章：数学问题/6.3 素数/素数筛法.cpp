#include <iostream>
#include <vector>
using namespace std;

vector<bool> isprime(10000);
vector<int> prime;

void initial(const int& n){
    for(int i=0;i<n;i++){
        if(i<2){
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
        initial(n);
        for(int i=0;i<prime.size();i++){
            if(prime[i]%10==1){
                cout << prime[i] << ' ';
            }
        }
        cout << endl;
    }
    return 0;
}