#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

long long dfs(long long lenth,long long x,long long y){
	if(lenth==0) return 0;
	long long diff=lenth/2;
	long long batchsum=diff*diff;
	
	if(x<diff && y<diff){ //第一象限 
		return dfs(diff,x,y);
	}
	else if(x<diff && y>=diff){ //第二象限 
		return batchsum+dfs(diff,x,y-diff); 
	} 
	else if(x>=diff && y<diff){ //第三象限 
		return 2*batchsum+dfs(diff,x-diff,y);
	}
	else {
		return 3*batchsum+dfs(diff,x-diff,y-diff);
	}
}

int main(){
	int n,T;
	cin >> n >> T;
	//网格的边长是 2^n 
	
	while(T--){
		long long a,b;
		cin >> a >> b;
		long long  lenth=1 << n;
		cout << dfs(lenth,a-1,b-1)+1 << endl;
	}
	return 0;
}
