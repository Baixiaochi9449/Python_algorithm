#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int binary_search(const vector<int>& arr,const int& x){
    int left=0;
    int right=arr.size()-1;
    while(left<=right){
        int mid=(left+right)/2;
        if(arr[mid]==x){
            return mid;
        }
        else if(arr[mid]<x){
            left=mid+1;
        }
        else{
            right=mid-1;
        }
    }
    return -1;
}

int main(){
    int n;
    while(scanf("%d",&n)!=EOF){
        int m;
        vector<int> arr(n);
        for (int i=0;i<n;i++){
            scanf("%d",&arr[i]);
        }
        scanf("%d",&m);
        vector<int> target(m);
        for (int i=0;i<m;i++){
            scanf("%d",&target[i]);
        }

        sort(arr.begin(),arr.end());
        for (int i=0;i<m;i++){
            if (binary_search(arr,target[i])!=-1){
                printf("YES\n");
            }
            else{
                printf("NO\n");
            }
            
        }
    }
    return 0;
}