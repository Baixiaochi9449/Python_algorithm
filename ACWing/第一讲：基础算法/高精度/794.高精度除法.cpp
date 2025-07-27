//倒序存储，保持一致。 除了输出C还要有 余数 ，所以传入参数的时候使用&， 这样原位置的值也变了
//每次运算的时候，从最后一位开始计算 r=r*10+A[i]  r=r%b  C[i]=r/b  初始值r=0;
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

vector<int> mod(vector<int>& A,int b,int& r){
  r=0;
  vector<int> C;
  for(int i=A.size()-1;i>=0;i--){
    r=r*10+A[i];
    C.push_back(r/b);
    r=r%b;
  }
  reverse(C.begin(),C.end());
  while(C.size()>1 && C.back()==0) C.pop_back();
  return C;
  
}

int main(){
  string a;
  int b;
  while(cin >> a >> b){
    if(a=="0") cout <<"0" << endl <<"0"<< endl;
    else{
      vector<int> A;
      for(int i=a.size()-1;i>=0;i--){
        A.push_back(a[i]-'0');
      }
      int r;
      vector<int> C=mod(A,b,r);
      for(int i=C.size()-1;i>=0;i--){
        cout<< C[i] ;
      }
      cout << endl;
      cout << r << endl;
    }
  }
  return 0;
  
}
