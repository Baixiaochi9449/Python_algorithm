#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
	int T;
	cin >> T;
	while(T--){
		int n;
		cin >> n;
		vector<int> nums(n);
		for(int i=0;i<n;i++){
			cin >> nums[i];
		}
		int maxnum=nums[0];
		int minnum=nums[0];
		int sum=0;
		for(int i=0;i<n;i++){
			sum+=nums[i];
			maxnum=max(maxnum,nums[i]);
			minnum=min(minnum,nums[i]);
		}
//		cout << maxnum << " " << minnum << endl;
//		cout << "sum :" << sum << endl;
		sum=sum-maxnum-minnum;
		double res=(double)sum/(n-2);
		printf("%.2f",res);
	}
	return 0;
}
