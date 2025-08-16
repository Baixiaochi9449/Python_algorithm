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
    sort(arr.begin(),arr.end());
    int res=0;
    for(int i=0;i<n;i++){
        res+=(abs(arr[i]-arr[n/2]));
    }
    cout << res << endl;
    return 0;
}