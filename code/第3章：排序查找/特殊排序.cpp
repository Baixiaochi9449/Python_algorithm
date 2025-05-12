#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int n=0;
    while(scanf("%d",&n)!=EOF){
        vector<int> arr(n);
        for (int i=0;i<n;i++){
            scanf("%d",&arr[i]);
        }

        auto max_pos=max_element(arr.begin(),arr.end());
        arr.erase(max_pos);

        sort(arr.begin(),arr.end());

        for (int i=0;i<n-1;i++){
            printf("%d ",arr[i]);
        }

    }
    return 0;
}