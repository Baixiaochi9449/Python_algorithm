#include <iostream>
#include <algorithm>

using namespace std;

int kmi(int a,int k,int p){
	long long res=1;
	while(k>0){
		if(k&1==1){ //个位是1的时候 
		
			res=(long long)res*a %p;
		}
		k/=2;
		a=(long long)a* a %p;
	}
	return res;
}

int main(){
	int n;
	cin >> n;
	while(n--){
		int b,p;
		cin >> b >> p;
		if(b%p==0) cout << "impossible" << endl;
		else {
			int res=kmi(b,(p-2),p);
			cout << res << endl;
		}
	}
	return 0;
}
