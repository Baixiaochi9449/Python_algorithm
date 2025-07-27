#include <iostream>
#include <vector>
using namespace std;

int N=1e6;
vector<int> b(N);
vector<int> a(N);

void insert(int l ,int r,int c){
  b[l]+=c;
  b[r+1]-=c;
}

int main(){
  int n,m;
  while(cin >> n >> m){
    
    for(int i=1;i<=n;i++){
      cin >> a[i];
    }
    
    //初始化b数组
    for(int i=1;i<=n;i++) insert(i,i,a[i]);
    //更新b数组
    while(m--){
      int l,r,c;
      cin >> l >> r >> c;
      insert(l,r,c);
    }
    
    for(int i=1;i<=n;i++) b[i]+=b[i-1];
    for(int i=1;i<=n;i++){
      cout << b[i] << " ";
    }
  }
  return 0;
}