#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

long long dfs(long long lenth,long long x,long long y){
	if(lenth==0) return 0;
	long long diff=lenth/2;
	long long batchsum=diff*diff;
	
	if(x<diff && y<diff){ //��һ���� 
		return dfs(diff,x,y);
	}
	else if(x<diff && y>=diff){ //�ڶ����� 
		return batchsum+dfs(diff,x,y-diff); 
	} 
	else if(x>=diff && y<diff){ //�������� 
		return 2*batchsum+dfs(diff,x-diff,y);
	}
	else {
		return 3*batchsum+dfs(diff,x-diff,y-diff);
	}
}

int main(){
	int n,T;
	cin >> n >> T;
	//����ı߳��� 2^n 
	
	while(T--){
		long long a,b;
		cin >> a >> b;
		long long  lenth=1 << n;
		cout << dfs(lenth,a-1,b-1)+1 << endl;
	}
	return 0;
}
