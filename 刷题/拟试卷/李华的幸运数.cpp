//一共4层， 每层有9种选择
#include <iostream>
#include <algorithm>
using namespace std;

int res;
void backtracking(int n,int cursum,int k){
	if(k==4){ //第四层 
		if(cursum==n) res++;
		return ;
	}
	if(cursum>n) return ;
	
	for(int i=-9;i<=9;i++){
		int num=i*i;
		if(num>n) continue;
		
		if(cursum+num>n) continue;
		
		cursum+=num;
		backtracking(n,cursum,k+1);
		cursum-=num;
	}
	return ;
}

int main(){
	int T;
	cin >> T;
	while(T--){
		int n;
		cin >> n;
		res=0;
		backtracking(n,0,0); 
		cout << res << endl;
	}
} 
