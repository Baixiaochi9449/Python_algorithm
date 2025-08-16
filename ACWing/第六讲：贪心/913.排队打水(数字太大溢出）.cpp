//所有人的等待时间最小，那就让打的快的人先打
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int n;
    cin >>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }
    sort(arr.begin(),arr.end());
    long long res=0;
    for(int i=0;i<n;i++){
        res+=(arr[i]*(n-1-i));
    }
    cout << res << endl;
    return 0;
}