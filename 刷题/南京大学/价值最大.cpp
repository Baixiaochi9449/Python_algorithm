//成本理解为重量
//要求背包装满的情况下，最大价值
//0-1  先物品，再倒序背包
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
	int n,k;
	cin >> n >> k;
	vector<int> value(n);
	vector<int> cost(n);
	for(int i=0;i<n;i++){
		cin >> value[i];
		cin >> cost[i];
	}
	
	vector<int> dp(k+1,-1); //dp[j] 背包容量为j的时候的最大价值
	dp[0]=0;
	for(int i=0;i<n;i++){
		for(int j=k;j>=cost[i];j--){
            if(dp[j-cost[i]]!=-1){
			    dp[j]=max(dp[j],dp[j-cost[i]]+value[i]);
            }
		}
	}
	//怎么判断满没满？
	if(dp[k]==-1) cout << 0 << endl;
    else	cout << dp[k] << endl;
	return 0; 
} 

//装满容量为j的背包有多少种方法  dp[j]+=dp[j-nums[i]]
