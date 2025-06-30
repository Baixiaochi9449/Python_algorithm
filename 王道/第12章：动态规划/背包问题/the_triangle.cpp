#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int n=0;
    while(scanf("%d",&n)!=EOF){
        vector<vector<int>> arr(n);
        for (int i=0;i<n;i++){
            arr[i].resize(i+1);
            for (int j=0;j<i+1;j++){
                scanf("%d",&arr[i][j]);
            }
        }
        vector<vector<int>> dp(n);
        for (int i=0;i<n;i++){
            dp[i].resize(i+1);
        }
        for (int j=0;j<n;j++){
            dp[n-1][j]=arr[n-1][j];
        }
        for (int i=n-2;i>=0;i--){
            for (int j=0;j<i+1;j++){
                dp[i][j]=max(dp[i+1][j],dp[i+1][j+1])+arr[i][j];   //噢~这个是把所有的节点的 总和都记录了下来
            }
        }
        printf("%d\n",dp[0][0]);
        // 不需要手动清除，因为 arr 和 dp 会在每次循环结束时自动销毁
    }
}