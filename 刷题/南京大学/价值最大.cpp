//�ɱ����Ϊ����
//Ҫ�󱳰�װ��������£�����ֵ
//0-1  ����Ʒ���ٵ��򱳰�
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
	
	vector<int> dp(k+1,-1); //dp[j] ��������Ϊj��ʱ�������ֵ
	dp[0]=0;
	for(int i=0;i<n;i++){
		for(int j=k;j>=cost[i];j--){
            if(dp[j-cost[i]]!=-1){
			    dp[j]=max(dp[j],dp[j-cost[i]]+value[i]);
            }
		}
	}
	//��ô�ж���û����
	if(dp[k]==-1) cout << 0 << endl;
    else	cout << dp[k] << endl;
	return 0; 
} 

//װ������Ϊj�ı����ж����ַ���  dp[j]+=dp[j-nums[i]]
