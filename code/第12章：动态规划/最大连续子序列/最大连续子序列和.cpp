// #include <iostream>
// #include <cstdio>
// #include <algorithm>
// using namespace std;

// const int MAX=1000000;
// long long S[MAX];     //把数组都定义到最前面了
// long long dp[MAX];    //发定义为全局变量

// long long maxsebsequence(int n){
//     long long current_max=S[0];
//     dp[0]=S[0];
//     for (int i=1;i<n;i++){
//         dp[i]=max(S[i],dp[i-1]+S[i]);
//         current_max=max(dp[i],current_max);
//     }
//     return current_max;
// }

// int main(){
//     int n=0;
//     long long max_sum=0;
//     while (scanf("%d",&n)!=EOF){
//         for (int i=0;i<n;i++){
//             scanf("%lld",&S[i]);
//         }
//         max_sum=maxsebsequence(n);
//         printf("%lld\n",max_sum);
        
//     }
//     return 0;
// }

//使用局部变量，避免出现数组干扰
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

long long max_subsequence(const vector<long long>& S){
    int n=S.size();
    vector<long long> dp(n);
    dp[0]=S[0];
    long long cur_max=S[0];
    for (int i=1;i<n;i++){
        dp[i]=max(dp[i-1]+S[i],S[i]);
        cur_max=max(cur_max,dp[i]);
    }
    return cur_max;
}

int main(){
    int n=0;
    long long sum_max=0;
    while (scanf("%d",&n)!=EOF){  //先读了n之后，再定义S（n)
        vector<long long> S(n); 
        for (int i=0;i<n;i++){
            scanf("%lld",&S[i]);
        }
        sum_max=max_subsequence(S);
        printf("%lld\n",sum_max);

    }
    return 0;
}