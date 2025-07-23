#include <iostream>
#include <vector>
using namespace std;

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
      // 查找左边界（第一个 >= target 的位置）
      int l=0,r=n-1;
      while(l<r){
        int mid=l+r >> 1;
        if(nums[mid]>=target) r=mid; //假设mid是左边界，那么满足nums[mid]<=target
        else l=mid+1;
      }
      if(nums[l]!=target) cout << -1 << " " << -1 << endl;
      else{
        cout << l << " ";
        
        //查找右边界（最后一个<=target的位置）
        int l=0,r=n-1;
        while(l<r){
          int mid=l+r+1 >> 1;
          if(nums[mid]<=target) l=mid;
          else r=mid-1;
        }
        cout << r << endl;
      }
    }
  }
  return 0;
}