#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
const int N=1e6 +10;
int vec[N];
void quick_sort(int vec[],int l, int r){
  if(l>=r) return ;  //只有一个或没有，就直接返回
  int x=vec[(l+r+1)/2];  //随意取一个值而已  
  int i = l-1;
  int j = r+1;
  while(i<j){
    do i++;while(vec[i]<x);
    do j--;while(vec[j]>x);
    if(i<j) swap(vec[i],vec[j]);
  }
  quick_sort(vec,l,i-1);
  quick_sort(vec,i,r);
}


int main(){
  int n,k;
  scanf("%d%d",&n&k);
  for(int i=0;i<n;i++){
    scanf("%d",&vec[i]);
  }
  quick_sort(vec,0,n-1);
  
  printf("%d\n",vec[k-1]);
  
}