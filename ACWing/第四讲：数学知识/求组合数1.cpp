#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

//C[a][b] �洢���е���
const int N=2020;
vector<vector<int> > C(N,vector<int>(N));
int mod=1e9+7; 
void init(){ 
	//��ʼ�������е�j=0��ʱ����1 ��j<=i  i=0��ʱ����0 
	for(int i=0;i<N;i++){
		for(int j=0;j<=i;j++){
			if(j==0) C[i][j]=1;  //i=0��ʱ��jֻ��=0,���Բ���Խ�� 
			else C[i][j]=(C[i-1][j]+C[i-1][j-1])%mod;
		}
	} 
} 

int main(){
	init();
	
	int n;
	cin >> n;
	while(n--){
		int a,b;
		cin >> a >> b;
		cout << C[a][b] << endl;
	}
	return 0;
}
