//i从前往后，j从后往前
#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n,m,target;
    cin >> n >> m >> target;
    vector<int> nums1(n);
    vector<int> nums2(n);
    for(int i=0;i<n;i++){
        cin >> nums1[i];
    }
    for(int j=0;j<m;j++){
        cin >> nums2[j];
    }
    int i=0,j=m-1;
    while(i<n && j>=0){
        if(nums2[j]>=target) j--;
        else if(nums1[i]+nums2[j]==target) break;
        else if(nums1[i]+nums2[j]<target) i++;
        else if(nums1[i]+nums2[j]>target) j--;
    }
    cout << i << " "<< j << endl;
    return 0;
}