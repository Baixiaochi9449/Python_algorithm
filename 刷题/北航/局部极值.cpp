#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
using namespace std;

int main(){
	int n,k;
	cin >> n >> k;
	vector<int> arr(n);
	for(int i=0;i<n;i++){
		cin >> arr[i];
	}
	//��û˵�����ֲ���Сֵ��˭
	 int begin=1;
	 int end=k;
	 int res=n-k;
	 cout << res << endl;
	 
}
