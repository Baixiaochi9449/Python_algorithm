#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

bool compare(const vector<int>& a,const vector<int>& b){
    if (a[0]==b[0]){
        return a[1]<b[1];
    }
    else{
        return a[0]<b[0];
    }
}

int main(){
    int n;
    while(scanf("%d",&n)!=EOF){
        vector<vector<int>> arr(n, vector<int>(2));;
        for (int i=0;i<n;i++){
            scanf("%d%d",&arr[i][0],&arr[i][1]);
        }

        sort(arr.begin(),arr.end(),compare);
        printf("%d %d",arr[0][0],arr[0][1]);

    }
    return 0;
}