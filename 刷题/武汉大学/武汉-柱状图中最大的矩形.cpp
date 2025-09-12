//矩形最大面积，长 高都要。 双指针从两边开始，遍历到相遇，记录面积最大的。
//最重要的常识：矮的往前移动
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }

    int res=0;
    if(n==1) res=arr[0];
    else{
        //暴力
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int min_h=arr[i];
                for(int k=i;k<=j;k++){
                    min_h=min(min_h,arr[k]);
                    
                }
                int cur=min_h*(j-i+1);
            
                res=max(res,cur);
            }
        }
    }
    cout << res << endl;
}
