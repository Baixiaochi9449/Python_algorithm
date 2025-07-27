//倒序存储到2个数组
//先判断大小，永远让 大数-小数
//每个数相减  A[i]-B[i]-t  t是借位，不是0 就是1，初始值为0

#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<int> C;

void sub(vector<int>& A,vector<int>& B){
  
  int t=0;
  for(int i=0;i<A.size();i++){
    t+=A[i];
    if(i<B.size()) t-=B[i];
    C.push_back((t+10)%10);
    if(t<0) t=-1;
    else t=0;
  }
  while(C.size()>1 && C.back()==0) C.pop_back();   //去掉C后面的0，即就是去掉前导0
  return ;
}

int main(){
  string a,b;
  while(cin >> a >> b){
    int n=a.size();
    int m=b.size();
    
    vector<int> A;
    vector<int> B;
    
    for(int i=n-1;i>=0;i--){
      A.push_back(a[i]-'0');
    }
    for(int i=m-1;i>=0;i--){
      B.push_back(b[i]-'0');
    }
    
    if(n>m) {
      sub(A,B);  //目前已经更新了C的值
      for(int i=C.size()-1;i>=0;i--){
          cout << C[i];
      }
    }
    
    if(n<m){
      sub(B,A);
      cout << "-";
      for(int i=C.size()-1;i>=0;i--){
          cout << C[i];
      }       
    }
    
    if(n==m){
      int j=0;
      while(j<n && a[j]==b[j]){
        j++;
      }
      if(j==n) cout << "0";
      else{
      
        if(a[j]>b[j]) {
          sub(A,B);
          for(int i=C.size()-1;i>=0;i--){
              cout << C[i];
          }
        }
        else{
          sub(B,A);
          cout << "-";
          for(int i=C.size()-1;i>=0;i--){
              cout << C[i];
          }     
        }
      }
    }
    
  }
  return 0;
}