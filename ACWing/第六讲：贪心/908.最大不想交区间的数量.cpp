
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
    vector<vector<int>> arr;
    for(int i=0;i<n;i++){
        int a,b;
        cin >> a >> b;
        arr.push_back({a,b});
    }
    sort(arr.begin(),arr.end(),compare);
    int end=arr[0][1];
    int res=1;
    for(int i=1;i<n;i++){
        if(end>=arr[i][0]){  //想交
            end=min(end,arr[i][1]);
        }
        else{
            res++;
            end=arr[i][1];
        }
    }
    cout << res << endl;
    return 0;
}