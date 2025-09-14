#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int mod=1e9+7;
const int N=1e5+10;
vector<int> fact(N);
vector<int> infact(N);

int kmi(int a,int k,int p){
	int res=1;
	while(k>0){
		if(k & 1){
			res=(long long)res* a %p;
		}
		k/=2;
		a=(long long )a*a %p;
	}
	return res;
} 

void init(){
	fact[0]=infact[0]=1;
	for(int i=1;i<N;i++){
		fact[i]=(long long)fact[i-1]* i%mod;  //正常取模
		infact[i]=(long long)infact[i-1]* kmi(i,mod-2,mod) %mod;  //对逆元取模 
	}
}

int main(){
	init();
//	cout << "4的阶乘的逆元" << infact[4]<< endl; 
	int n;
	cin >> n;
	while(n--){
		int a,b;
		cin >> a >> b;
		int res=(long long)fact[a]*infact[b]%mod *infact[a-b]%mod;
		cout << res << endl;
	}	
	return 0;
}
