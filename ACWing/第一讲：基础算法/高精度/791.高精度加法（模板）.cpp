//把字符串倒序保存到数组里,每次相加都是 A[i]+B[i]+r   r=..  C[i]=..
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(){
  string num1,num2;
  while(cin >> num1 >> num2){
    int n=num1.size();
    int m=num2.size();
    int c=max(n,m)+1;
    vector<int> A;
    vector<int> B;
    vector<int> C(c,0);
    for(int i=n-1;i>=0;i--){
      A.push_back(num1[i]-'0');
    }
    for(int i=m-1;i>=0;i--){
      B.push_back(num2[i]-'0');
    }
    int r=0;
    for(int i=0;i<c;i++){
      if(i<n) r+=A[i];
      if(i<m) r+=B[i];
      C[c-i-1]=r%10;
      r=r/10;
    }
    if(C[0]==0){
      for(int i=1;i<c;i++){
        cout << C[i];
      }
    }
    else{
      for(int i=0;i<c;i++){
        cout << C[i];
      }
    }
  }
  return 0;
}