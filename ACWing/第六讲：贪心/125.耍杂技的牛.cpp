//尽可能让重的牛在下面
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//按照左边界从小到大排序
bool compare(vector<int>& a, vector<int>& b){
    return (a[0]+a[1])<(b[0]+b[1]);
}

int main(){
    int n;
    cin >>n;
    vector<vector<int>> arr;
    for(int i=0;i<n;i++){
        int a,b;
        cin >> a >> b;
        arr.push_back({a,b});
    }
    sort(arr.begin(),arr.end(),compare);
    int weight_sum=0;
    int res=-1e9;
    for(int i=0;i<n;i++){
        
        res=max(res,weight_sum-arr[i][1]);
        
        weight_sum+=arr[i][0];
    }
    cout << res << endl;
    return 0;
}