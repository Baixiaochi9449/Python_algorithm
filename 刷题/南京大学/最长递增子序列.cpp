#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
	vector<int> arr(2500);
	int n=0;
	while(cin >> arr[n]) n++;
	//�������һ���� i ����
	vector<int> dp(n,1); //dp[i] ��i��β�������
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
