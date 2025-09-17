//枚举一个中位数，然后判断1000作为中位数的话，右边的值需要增加多少

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
	
	cin >> n >> k;  //n一定是奇数 
	vector<int> arr(n);
	for(int i=0;i<n;i++){
		cin >> arr[i];
	} 
	//中位数必须是从小到大排序的
	sort(arr.begin(),arr.end()); 
	//开始枚举中位数
	long long l=0,r=2*1e9;
	while(l<r){
		int mid=(l+r+1)/2;
		if(check(mid,arr)) l=mid;
		else r=mid-1;
	} 
	
	cout << l << endl;
	return 0;
}
