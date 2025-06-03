#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int max_subsequence(const vector<int>& S){
    int n = S.size();
    vector<int> dp(n);
    dp[0] =S[0];
    int cur_max = S[0];
    for (int i=1; i < n;i++){
        dp[i]=max(dp[i-1]+S[i],S[i]);
        cur_max = max(cur_max, dp[i]);
    }
    return cur_max;
}

int main(){
    int n=0;
    while(scanf("%d",&n)!=EOF){
        vector<vector<int>> arr(n,vector<int>(n));
        vector<vector<int>> dp(n+1,vector<int>(n));
        for (int i=0;i<n;i++){
            for (int j=0;j<n;j++){
                scanf("%d",&arr[i][j]);
            }
        }
        for (int i=0;i<n+1;i++){
            for (int j=0;j<n;j++){
                if (i==0){
                    dp[i][j]=0;
                }
                else{
                    dp[i][j]=dp[i-1][j]+arr[i-1][j];
                }
            }
        }
        
        vector<int> temp(n);
        int max_sum=arr[0][0];
        int current_max=arr[0][0];
        for (int top=0;top<n;top++){
            for (int bottom=top+1;bottom<n+1;bottom++){
                for (int j=0;j<n;j++){
                    temp[j]=dp[bottom][j]-dp[top][j];
                }
                current_max=max_subsequence(temp);
                if(current_max>max_sum){
                    max_sum=current_max;
                }
    
            }
        }
        printf("%d\n",max_sum);
        }
        return 0;
    }
    
