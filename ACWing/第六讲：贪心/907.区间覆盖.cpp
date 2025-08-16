//按照左端点排序。 找到能覆盖start的区间（arr[i][0]<=start） 的最大的右边界（while循环）
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool compare(vector<int>& a,vector<int>& b){
    return a[0]<b[0];
}

int main(){
    int start,end;
    cin >> start >> end;
    int n;
    cin >> n;
    vector<vector<int>> arr;
    for(int i=0;i<n;i++){
        int a,b;
        cin >> a >>b;
        arr.push_back({a,b});
    }
    sort(arr.begin(),arr.end(),compare);
    int res=0;
    bool success=false;
    for(int i=0;i<n;i++){
        int j=i,  max_r=-1e9;  //每次更新start后，都要重新找max_r,所以max_r要在每次循环的时候，重新初始化为最小值。
        while(j<n && arr[j][0]<=start){  //能覆盖start的区间
            max_r=max(max_r,arr[j][1]);
            j++;
        }
        if(max_r<start){  //最大的r都小于start,（即区间并不包含start）
            res=-1;
            break;
        }
        //已经没有能覆盖start的区间了
        res++;
        if(max_r>=end){
            success=true;
            break;
        }
        start=max_r;
        i=j-1;
    }
    if(!success) res=-1;
    cout << res << endl;
}