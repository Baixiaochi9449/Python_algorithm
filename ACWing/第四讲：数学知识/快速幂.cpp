#include <iostream>
#include <algorithm>

using namespace std;


int kmi(int a,int k,int p){
	long long res=1;
	while(k>0){
		if(k&1){  //Ä©Î²ÊÇ1 
			res=(long long)res*a %p;
		}
		k/=2;
		a=(long long)a*a %p;
	}
	return res;
}

int main(){
	int n;
	cin >> n;
	while(n--){
		int a ,k,p;
		cin >> a >> k >> p;
		int res=kmi(a,k,p);
		cout << res << endl;
	}
	return 0;
} 
