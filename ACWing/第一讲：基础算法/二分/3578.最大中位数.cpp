#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool check(long long mid,vector<long long>& nums,long long k){
  //依次枚举，看看k够不够
  long long n=nums.size();
  long long result=0;
  for(long long i=n/2;i<n;i++){
    if(nums[i]<mid) result+=(mid-nums[i]);
  }
  if(result<=k) return true;
  else return false;
}

int main(){
  long long n,k;
  while(cin >> n >> k){
    vector<long long> nums(n);
    for(long long i=0;i<n;i++){
      cin >> nums[i];
    }
    sort(nums.begin(),nums.end());
    
    long long l=0,r=2e9;
    while(l<r){
      long long mid=((r+l+1)/2);
      if(check(mid,nums,k)) l=mid;           //mid满足要求，mid能满足 k够，所以mid能更大，所以变右区间
      else r=mid-1;
    }
    cout << l << endl;
  }
  return 0;
}