#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
	vector<int> arr(2500);
	int n=0;
	while(cin >> arr[n]) n++;
	//数组个数一共到 i 个数
	vector<int> dp(n,1); //dp[i] 以i结尾的最长递增
	int res=0;
	for(int i=0;i<n;i++){
		for(int j=i-1;j>=0;j--){
			if(arr[j]<arr[i]){
				dp[i]=max(dp[i],dp[j]+1);
			}
			res=max(dp[i],res);
		}
	} 
	cout << res << endl;
	return 0;
} 
