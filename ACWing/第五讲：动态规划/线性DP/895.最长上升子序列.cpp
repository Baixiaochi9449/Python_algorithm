//没有说是连续的，所以要把i前面的全都找一遍
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> nums(n);
    for(int i=0;i<n;i++){
        cin >> nums[i];
    }
    vector<int> dp(n,1); //dp[i] 以i结尾的数字，的最大递增序列长度
    int res=1;
    for(int i=1;i<n;i++){
        for(int j=0;j<i;j++){
            if(nums[j]<nums[i]){
                dp[i]=max(dp[i],dp[j]+1);
            }
        }
        res=max(res,dp[i]);
    }
    cout << res << endl;
    return 0;
}