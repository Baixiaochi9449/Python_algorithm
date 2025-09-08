//按照左端点排序，找右端点的最大值
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool compare(vector<int>& a,vector<int>& b){
    return a[0]<b[0];
}

int main(){
    int n;
    cin >> n;
    vector<vector<int>> arr(n,vector<int>(2));
    for(int i=0;i<n;i++){
        cin >> arr[i][0] >> arr[i][1];
    }
    sort(arr.begin(),arr.end(),compare);
    
    int res=0;
    int i=0;
    while(i<n){
        int j=i+1,end=arr[i][1];
        while(j<n && arr[j][0]<=end){
            end=max(end,arr[j][1]);
            j++;
        }
        res++;
        i=j;
    }
    cout << res << endl;
    return 0;
}