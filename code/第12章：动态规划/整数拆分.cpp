#include <iostream>
#include <cstdio>
using namespace std;

int main(){
    int n=0;
    while(scanf("%d",&n)!=EOF){
        int dp[n+1];
        dp[0]=1;//这里要注意一下
        dp[1]=1;
        for (int i=2;i<=n;i++){
            if (i%2!=0){
                dp[i]=dp[i-1];  //只是在前面拆分的基础上，每个部分都加了1
            }
            else{
                dp[i]=dp[i-1]+dp[i/2];  //带1的+全偶数的  带1的就是上一个奇数的情况，全偶数的就是在i/2的基础上每个部分都*2了，但是拆分方式不变
            }
        }
        printf("%d",dp[n]);
    }
}