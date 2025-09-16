#include <iostream>
#include <algorithm>
#include <cmath>
#include <map>
using namespace std;

const int mod=1e9+7;

int main(){
	int n;
	cin >> n;
	map<int,int> memo;
	for(int i=0;i<n;i++){
		int num;
		cin >> num;
		for(int i=2;i<=sqrt(num);i++){
			while(num%i==0){
				memo[i]++;
				num/=i;
			}
		}
		if(num>1) memo[num]++;
	}
	long long res=1; 
	for(auto cur:memo){
		int a=cur.first;
		int b=cur.second;
		//a的0次方 一直加到 a的b次方
		long long temp=1;
		for(int i=0;i<b;i++){
			temp=(long long)(temp*a+1)%mod;
		}
		res=(long long)res*temp %mod;
	}
	
	cout << res << endl;
	return 0;
}
