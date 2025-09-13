//��̬�滮��dp[i][j]=min(���ϣ�����+1�� ��ʼ����һ�к͵�һ�� 
//dp���������ı߳�
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main(){
	int n,m;
	cin >> n >> m;
	vector<vector<char> > graph(n,vector<char>(m));
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin >> graph[i][j];
		}
	}
	
	vector<vector<int> > dp(n+1,vector<int>(m+1,0));
	//��д��n+1 ��m+1�Ͳ��ó�ʼ����
	int res=0;
	for(int i=1;i<=n;i++){
	 	for(int j=1;j<=m;j++){
	 		if(graph[i-1][j-1]=='.'){
			 
		 		dp[i][j]=min(dp[i-1][j],min(dp[i][j-1],dp[i-1][j-1]))+1;
		 		res=max(res,dp[i][j]);
	 		}
		 }
	} 
	int sum=res*res;
	cout << sum << endl;
	return 0;
	 
}

//����i=1 i<=n �� j<=m   dp[i][j]��������д��һ��Ҫע��ԭͼ�Ͳ�������д�����ʲô��û����������п�����Խ���ˣ�����Խ���ˡ� 
