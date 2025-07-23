#include <iostream>
#include <vector>
using namespace std;

int main(){
  double target;
  while(cin >> target){
    double l=-22;
    double r=22;
    while(r-l>1e-8){  //如果单纯的r>l，可能一直循环下去了，要让他们之间有个最小差值
      double mid=(l+r)/2;
      if(mid*mid*mid<=target) l=mid;
      else r=mid; //不能减一加一，因为1的范围跨越太大
    }
    printf("%.6f",l);
  }
  return 0;
}