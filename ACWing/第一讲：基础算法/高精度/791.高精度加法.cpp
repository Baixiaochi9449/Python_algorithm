//长度100000，不是最大。 所以需要用string
//当前位
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(){
  string num1,num2;
  while(cin >> num1 >> num2){
    //最后结果的位数是最大数的位数--最大数位数+1
    int n=max(num1.size(),num2.size())+1;
    vector<int> result(n,0);
    
    int k=n-1;
    int i=num1.size()-1,j=num2.size()-1;
    while(i>=0 && j>=0){
      int temp=(num1[i]-'0')+(num2[j]-'0');
      result[k]=temp;
      k--;
      i--;
      j--;
    }
    while(i>=0){
      result[k]=num1[i]-'0';
      k--;
      i--;
    }
    while(j>=0){
      result[k]=num2[j]-'0';
      j--;
      k--;
    }
    for(int k=n-1;k>=0;k--){
      result[k-1]+=result[k]/10;
      result[k]=result[k]%10;
    }
    if(result[0]==0){
      for(int k=1;k<n;k++){
        cout<< result[k];
      }
    }
    else{
      for(int k=0;k<n;k++){
        cout << result[k];
      }
    }
  }
}