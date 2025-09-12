#include <iostream>
#include <vector>
#include <unordered_map>
#include <cmath>
#include <algorithm>
using namespace std;

const int N=4*1e4;
vector<bool> isprime(N,true);
void init(){
    isprime[0]=false;
    isprime[1]=false;
    for(int i=2;i<N;i++){
        if(isprime[i]){
            for(int j=i*i;j<N;j+=i){
                isprime[j]=false;
            }
        }
    }
}

bool compare(pair<int,int>& a,pair<int,int>& b){
    return a.first<b.first;
}

int main(){
    init();
   
    int n;
    cin >> n;
    while(n--){
        int num;
        unordered_map<int,int> res;
        cin >> num;
        for(int i=2;i<=sqrt(num);i++){
            if(!isprime[i]) continue;
            while(num>0 && num%i==0){
                res[i]++;
                num/=i;
            }
        }
      
        if(num>1){
            res[num]=1;
        }
        
        vector<pair<int,int>> ans;
        for(auto it=res.begin();it!=res.end();it++){
            int a=it->first; int b=it->second;
            ans.push_back({a,b});
        }
        sort(ans.begin(),ans.end(),compare);
        for(int i=0;i<ans.size();i++){
            cout << ans[i].first << ' '<< ans[i].second << endl;
        }
        cout << endl;
    }
    return 0;
}