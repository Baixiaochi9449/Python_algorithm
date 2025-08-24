//哈希表是 把字符串映射为一个不重复的数
//尝试用unordered_set呢？
#include <iostream>
#include <cstdio>
using namespace std;

typedef unsigned long long ULL;
int P=131;
const int N=100010;
ULL p[N];
ULL h[N];

ULL get_hash(int l,int r){
    return h[r]-h[l-1]*p[r-l+1];
}

int main(){
    int n,m;
    cin >> n >> m;
    string s;
    cin >> s;
    
    p[0]=1;
    for(int i=1;i<=N;i++){
        p[i]=p[i-1]*P;
        h[i]=h[i-1]*P +s[i-1];
    }
    
    while(m--){
        int i,j,x,y;
        cin >> i >> j >> x >> y;
        ULL hash1=get_hash(i,j);
        ULL hash2=get_hash(x,y);
        if(hash1==hash2) cout<< "Yes" << endl;
        else cout << "No" << endl;
    }
    return 0;
}