//可以只遍历输入进去的数
//用一个unordered_map
#include <iostream>
#include <unordered_map>
#include <cstdio>
using namespace std;

int main(){
    int n,m;
    cin >> n >> m;
    unordered_map<int,int> memo; 
    while(n--){
        int a ,b;
        cin >> a >> b;
        memo[a]+=b;
    }
    while(m--){
        int l,r;
        cin >> l >> r;
        int res=0;
        for(auto it =memo.begin();it!=memo.end();it++){
            if(it->first>=l && it->first<=r) {
                res+=it->second;
            }
        }
        cout << res << endl;
    }
    return 0;
}