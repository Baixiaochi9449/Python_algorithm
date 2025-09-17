// ö��ĳ��λ�õ�ֵ���ж�����Ҫ��kǰ�� ������Ҫ<=k �൱������߽磿
#include <iostream>
#include <algorithm>
using namespace std;

int n,m,k;

bool check(int mid){
	//��ǰֵ��mid  ȥ��mid���ڵ�λ��
	int j=m;
	long long pos=0;
	for(int i=1;i<=n;i++){
//		int j=m;
		while(j>=0 && i*j>mid) j--;
		pos+=j; //��ǰ��ȫ�����㣬��+j, ��ǰ�в������㣬��j-- 
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
