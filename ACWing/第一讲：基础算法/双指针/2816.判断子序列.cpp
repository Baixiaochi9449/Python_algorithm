//直接b中找到a了，j++,i++,  没找到j++
#include <iostream>
#include <vector>
using namespace std;
int main(){
    int n,m;
    cin >> n >> m;
    vector<int> nums1(n);
    vector<int> nums2(m);
    for(int i=0;i<n;i++){
        cin >>nums1[i];
    }
    for(int j=0;j<m;j++){
        cin >> nums2[j];
    }
    int i=0,j=0;
    while(i<n && j<m){
        if(nums1[i]==nums2[j]) {
            i++;
            j++;
        }
        else{
            j++;
        }
    }
    if(i==n){
        cout << "Yes" << endl;
    }
    else cout << "No" << endl;
    return 0;
}