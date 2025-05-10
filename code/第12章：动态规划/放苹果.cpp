#include <iostream>
#include <cstdio>
using namespace std;

int main(){
    int M=0;
    int N=0;
    while (scanf("%d",&M)!=EOF){
        scanf("%d",&N);
        int dp[M+1][N+1];
        for (int i=0;i<=N;i++){
            dp[0][i]=1;  //0 apple have 1
        }
        for (int i=1;i<=M;i++){
            dp[i][1]=1;   //只有一个盘子有一种分法
        }
        for (int i=1;i<=M;i++){
            for (int j=2;j<=N;j++){
                if (i<j){
                    dp[i][j]=dp[i][i];
                }
                else{
                    dp[i][j]=dp[i-j][j]+dp[i][j-1];
                }
            
            }
        }
        printf("%d",dp[M][N]);

    }

}