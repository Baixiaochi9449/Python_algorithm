//动态规划，dp[i][j]=min(左，上，右上+1） 初始化第一行和第一列 
//dp代表的是最长的边长
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
	//都写成n+1 和m+1就不用初始化了
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

//当有i=1 i<=n 且 j<=m   dp[i][j]可以这样写，一定要注意原图就不能这样写，如果什么都没有输出，就有可能是越界了，数组越界了。 
