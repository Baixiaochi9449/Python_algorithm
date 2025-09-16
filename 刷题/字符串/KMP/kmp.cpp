#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<int> get_next(string pattern){
	int j=0;
	int n=pattern.size();
	vector<int> next(n,0); //初始全是0？ 
	for(int i=1;i<n;i++){   //这里i要用1开始 
		while(j>0 && pattern[i]!=pattern[j]){
			j=next[j-1];
		}
		if(pattern[i]==pattern[j]) j++;
		next[i]=j; 
	}
	return next;
}

int main(){
	int n,m;
	string str,pattern;
	cin >> m >> pattern;
	cin >> n >> str;
	vector<int> next=get_next(pattern);
//	for(int i=0;i<n;i++){
//		cout << next[i] << "" ;
//	}
	int j=0;
	for(int i=0;i<n;i++){
		while(j>0 && pattern[j]!=str[i]){
			j=next[j-1];
		}
		if(pattern[j]==str[i]) j++;
		if(j==m){
			cout << i-m+1<<" ";
			j=next[j-1];
		}
	}
	return 0;
	
}
