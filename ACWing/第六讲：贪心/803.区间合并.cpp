//题意就是在求，不重叠的区间的个数
//首先按照左端点排序，只要下一个区间的左端点<=max_r ,就说明重复。  然后维护一个max_r , 直到找到不重复 res++
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
    vector<vector<int>> arr;
    for(int i=0;i<n;i++){
        int l,r;
        cin >> l >> r;
        arr.push_back({l,r});
    }
    sort(arr.begin(),arr.end(),compare);
    int res=0;
    for(int i=0;i<n;i++){
        int j=i+1,max_r=arr[i][1];
        while(j<n && arr[j][0]<=max_r){  //当重叠的时候
            max_r=max(max_r,arr[j][1]);
            j++;
        }
        i=j-1;
        res++;
    }
    cout << res << endl;
    return 0;
}