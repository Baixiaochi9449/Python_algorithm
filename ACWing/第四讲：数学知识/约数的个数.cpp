//先暴力算出来
//求质因数的时候， 2--- 2^1   6---2^1  + 3^1   所    
#include <iostream>
#include <vector>
#include <cmath>
#include <unordered_map>
using namespace std;

const int mod=1e9+7;

int main(){
    int n;
    cin >> n;
    unordered_map<int,int> memo;
    while(n--){
        int temp;
        cin >> temp;
        //先找temp的质因数
        for(int i=2;i<=sqrt(temp);i++){
            while(temp>0 && temp%i==0){
                memo[i]++;
                temp/=i;
            }
        }
        //最多有一个大于sqrt的质因数
        if(temp>1) memo[temp]++;
    }
    //n个数的质因数个数都找到了
    long long  res=1;
    for(auto it=memo.begin();it!=memo.end();it++){
        res*=(it->second+1);
        res=res%mod;
    }
    cout << res%mod << endl;
    return 0;
}
