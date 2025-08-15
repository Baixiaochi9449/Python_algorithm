//找出不重叠区间的数量：按照右边界排序  直接找大于end的start
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool compare(vector<int>& a,vector<int>& b){
    return a[1]<b[1];
}

int main(){
    int n;
    cin >> n;
    vector<vector<int>> arr(n);
    for(int i=0;i<n;i++){
        int a,b;
        cin >> a >> b;
        arr[i]={a,b};
    }
    sort(arr.begin(),arr.end(),compare);
    int end=arr[0][1];
    int res=1;
    for(int i=1;i<arr.size();i++){
        if(end>=arr[i][0]){ //有重叠
            end=min(end,arr[i][1]);
        }
        else{ //无重叠
            res++;
            end=arr[i][1];
        }
    }
    cout << res << endl;
    return 0;
}