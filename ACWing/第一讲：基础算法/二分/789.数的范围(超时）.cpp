#include <iostream>
#include <vector>
using namespace std;

vector<int> search(vector<int>& nums,int target){
  int left=0;
  int right=nums.size()-1;
  while(left<=right){
    int mid=(left+right)/2;
    if(target>nums[mid]){
      left=mid+1;
    }
    if(target<nums[mid]){
      right=mid-1;
    }
    if(target==nums[mid]){
      int begin=mid;
      int end=mid;
      while(nums[begin]==target && begin>=0){
        begin--;
      }
      while(nums[end]==target && end<nums.size()){
        end++;
      }
      return {begin+1,end-1};
    }
  }
  return {-1,-1};
}

int main(){
  int n,q;
  while(cin >> n >> q){
    vector<int> nums(n);
    for(int i=0;i<n;i++){
      cin >> nums[i];
    }
    while(q--){
      int target;
      cin >> target;
      vector<int> result(2,-1);
      result = search(nums,target);
      cout << result[0] << " "<< result[1] << endl;
    }
  }
}