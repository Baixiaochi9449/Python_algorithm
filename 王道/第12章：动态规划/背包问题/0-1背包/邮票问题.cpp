#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int num_p=0;
    int n=0;
    while (scanf("%d%d",&num_p,&n)!=EOF){
        vector<int> P(n);
        vector<int> dp(num_p+1,100000); //如何把dp初始化为不可达
        for (int i=0;i<n;i++){
            scanf("%d",&P[i]);
        }
        dp[0]=0;
        for (int i=0;i<n;i++){
            for (int j=num_p;j>=P[i];j--){
                dp[j]=min(dp[j-P[i]]+1,dp[j]);
            }
        }
        if (dp[num_p]<=n){
            printf("%d\n",dp[num_p]);
        }
        else{
            printf("0\n");
        }


    }
}