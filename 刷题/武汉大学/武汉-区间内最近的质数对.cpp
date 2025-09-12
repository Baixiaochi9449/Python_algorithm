//素数筛选法找到所有的素数，然后再计算
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int N=1000;
int main() {
	vector<bool> isprime(N,true);
	isprime[1]=false;
	for(int i=2; i<N; i++) {
		if(isprime[i]) {
			for(int j=i*i; j<N; j+=i) {
				isprime[j]=false;
			}
		}
	}
	int n;
	cin >> n;
	while(n--){
		int l,r;
		cin >> l >> r;
		int min_len=1e6;
		pair<int,int> res;
		res.first=-1;
		res.second=-1;
		vector<int> prime;
		for(int i=l; i<=r; i++) {
			if(isprime[i]) prime.push_back(i);
		}
		if(prime.size()>=2) {
			for(int i=0; i<prime.size()-1; i++) {
				int curlen=prime[i+1]-prime[i];
				if(curlen<min_len) {
					min_len=curlen;
					res= {prime[i],prime[i+1]};
				}
			}
		}
		cout << res.first <<" "<< res.second << endl;
	}
	return 0;
}
