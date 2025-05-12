#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int n;
    if (scanf("%d",&n)!=EOF){
        vector<int> arr(n);
        int x;
        for (int i=0;i<n;i++){
            scanf("%d",&arr[i]);
        }
        scanf("%d",&x);

        auto it=find(arr.begin(),arr.end(),x);
        if(it!=arr.end()){
            int idx=distance(arr.begin(),it);
            printf("%d\n",idx);
        }
        else{
            printf("-1");
        }

    }
    return 0;
}