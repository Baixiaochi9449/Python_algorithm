//归并排序： 先排左边，再排右边，然后定义一个新数组，把两个数组（p的左右两边）的值放到新数组中，然后再把新数组放回原数组
#include <iostream>
using namespace std;

const int N=1e6+10;
int p[N];
void merge_quick(int l,int r){
  //如果只有1个元素或者没有
  if(l>=r) return ;
  //首先选取中间的坐标
  int mid = (l+r)/2;
  merge_quick(l,mid);
  merge_quick(mid+1,r);
  int temp[r+1];
  int i=l,j=mid+1;
  int k=l;
  while(i<=mid && j<=r){
    if(p[i]<=p[j]){
      temp[k]=p[i];
      i++;
      k++;
    }
    else{
      temp[k]=p[j];
      j++;
      k++;
    }
  }
  while(i<=mid){
    temp[k]= p[i];
    i++;
    k++;
  }
  while(j<=r){
    temp[k]=p[j];
    j++;
    k++;
  }
  for(int k=l;k<=r;k++){
    p[k]=temp[k];
  }
  
}
int main(){
  int n;
  while(cin >> n){
    for(int i=0;i<n;i++){
      cin >> p[i];
    }
    merge_quick(0,n-1);
    for(int i=0;i<n;i++){
      cout << p[i] << ' ';
    }
  }
}