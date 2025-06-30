#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int n;
    while(scanf("%d",&n)!=EOF){
        vector<int> arr(n);
        for (int i=0;i<n;i++){
            scanf("%d",&arr[i]);
        }
        if (arr[0]!=arr[1]){
            printf("0 ");
        }
        for (int i=1;i<n-1;i++){
            if (arr[i]>arr[i-1] && arr[i]>arr[i+1]){
                printf("%d ",i);
            }
            if (arr[i]<arr[i-1] && arr[i]<arr[i+1]){
                printf("%d ",i);
            }
        }
        if (arr[n-1]!=arr[n-2]){
            printf("%d\n",n-1);
        }
        else{
            printf("\n");
        }
    }
    return 0;
}