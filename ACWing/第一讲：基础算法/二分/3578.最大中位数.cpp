//ö��һ����λ����Ȼ���ж�1000��Ϊ��λ���Ļ����ұߵ�ֵ��Ҫ���Ӷ���

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n,k;

bool check(int mid,vector<int>& arr){
	int pos=n/2;
	long long need=0;
	for(int i=pos;i<n;i++){
		if(mid>arr[i]){
			need+=(long long)(mid-arr[i]) ;
		}
	}
	if(need>k) return false;
	else return true;
}

int main(){
	
	cin >> n >> k;  //nһ�������� 
	vector<int> arr(n);
	for(int i=0;i<n;i++){
		cin >> arr[i];
	} 
	//��λ�������Ǵ�С���������
	sort(arr.begin(),arr.end()); 
	//��ʼö����λ��
	long long l=0,r=2*1e9;
	while(l<r){
		int mid=(l+r+1)/2;
		if(check(mid,arr)) l=mid;
		else r=mid-1;
	} 
	
	cout << l << endl;
	return 0;
}
