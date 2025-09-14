#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

//C[a][b] 存储所有的数
const int N=2020;
vector<vector<int> > C(N,vector<int>(N));
int mod=1e9+7; 
void init(){ 
	//初始化，所有的j=0的时候是1 ，j<=i  i=0的时候都是0 
	for(int i=0;i<N;i++){
		for(int j=0;j<=i;j++){
			if(j==0) C[i][j]=1;  //i=0的时候，j只能=0,所以不会越界 
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
