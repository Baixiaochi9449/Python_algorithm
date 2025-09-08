//dp[j]背包容量为j时候的最大价值
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int n,m;
    cin >> n >> m;  //背包最大容量m
    vector<int> val(n);  //价值
    vector<int> v(n);  //体积
    for(int i=0;i<n;i++){
        cin >> v[i] >> val[i];
    }
    vector<int> dp(m+1,0);
    dp[0]=0;
    for(int i=0;i<n;i++){
        for(int j=v[i];j<=m;j++){
            dp[j]=max(dp[j],dp[j-v[i]]+val[i]);
        }
    }
    cout << dp[m] << endl;
    return 0;
}