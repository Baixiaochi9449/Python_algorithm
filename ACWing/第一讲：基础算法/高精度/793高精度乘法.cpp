//长的数 *短的数
//把a倒序存储在A里
//每个数相乘的时候  A[i]*b +t  t=(A[i]*b+t)/10  C[i]=(A[i]*b +t)%10  初始t=0;
#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<long long> mul(vector<long long> A,long long b){
  long long t=0;
  vector<long long> C;
  for(long long i=0;i<A.size();i++){
    long long cur=A[i]*b+t;
    C.push_back(cur%10);
    t=cur/10;
  }
  //不会有前导0吧？
  if(t>0) C.push_back(t);  //这个是最头上的进位
  return C;
}

int main(){
  string a;
  long long b;
  while(cin >> a >> b){
    if(a=="0" || b==0) cout << "0";
    else{
      vector<long long> A;
      for(long long i=a.size()-1;i>=0;i--){
        A.push_back(a[i]-'0');
      }
      vector<long long> C= mul(A,b);
      for(long long i=C.size()-1;i>=0;i--){
        cout << C[i];
      }
    }
  }
  return 0;
}