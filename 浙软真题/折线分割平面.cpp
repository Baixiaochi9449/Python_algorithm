#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
	int n;
	cin >> n;
	//�ȼ���n��ֱ�����ֶ���ƽ��
	vector<int> arr(100010,0);
	arr[0]=1;
	for(int i=1;i<=100010;i++){
		arr[i]=arr[i-1]+i;
	} 
	int res=arr[2*n]-2*n;
	cout << res << endl;
	return 0; 
}
