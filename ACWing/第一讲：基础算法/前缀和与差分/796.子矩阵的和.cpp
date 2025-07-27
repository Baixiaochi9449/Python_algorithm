//初始化b数组，都是用一个insert函数，这个insert函数怎么写
#include <iostream>
#include <vector>

using namespace std;

void insert(int x1,int y1,int x2,int y2){
  
}

int main(){
  int n,m,q;
  while(cin >> n >> m >> q){
    vector<vector<int>> a(m+1,vector<int>(n+1,0));
    for(int i=1;i<=n;i++){
      for(int j=1;j<=m;j++){
        cin >> a[i][j];
      }
    }
    vector<vector<int>> s(m+1,vector<int>(n+1,0));
    for(int i=1;i<=n;i++){
      for(int j=1;j<=m;j++){
        s[i][j]=s[i-1][j]+s[i][j-1]-s[i-1][j-1]+a[i][j];
      }
    }
    while(q--){
      int x1,y1,x2,y2;
      cin >> x1 >> y1 >> x2 >> y2;
      int result=0;
      result=s[x2][y2]-s[x1-1][y2]-s[x2][y1-1]+s[x1-1][y1-1];
      cout << result << endl;
    }
  }
  return 0;
}