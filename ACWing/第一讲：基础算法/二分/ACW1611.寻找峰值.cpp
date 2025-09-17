// 枚举某个位置的值，判断它不要在k前面 ，它需要<=k 相当于找左边界？
#include <iostream>
#include <algorithm>
using namespace std;

int n,m,k;

bool check(int mid){
	//当前值是mid  去找mid所在的位置
	int j=m;
	long long pos=0;
	for(int i=1;i<=n;i++){
//		int j=m;
		while(j>=0 && i*j>mid) j--;
		pos+=j; //当前行全部满足，就+j, 当前行部分满足，就j-- 
	}
	return pos>=k; 
}

int main(){
	
	cin >> n >> m >> k;
	
	
	long long l=0,r=1ll*n*m;
	while(l<=r){
		int mid=(l+r+1)/2;
		if(check(mid)) l=mid;
		else r=mid-1;
	}
	cout << l << endl;
	return 0;
} 
