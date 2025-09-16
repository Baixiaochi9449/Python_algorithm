#include <map>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

bool compare(pair<string,int>& a,pair<string,int>& b){
	if(a.second==b.second){
		return a.first<b.first;
	}
	else return a.second>b.second;
}

int main(){
	string line;
	getline(cin , line);
	int n=line.size();
	map<string,int> memo;
    int i=0;
	while(i<n){
		int right=n;
		for(int j=i+1;j<n;j++){
			if(line[j]==' '){
				right=j;
                break;
			}
		}
		int len=right-i;
		string temp=line.substr(i,len);
		memo[temp]++;
        i=right+1;
	}
	
	vector<pair<string,int> > res;
	for(auto it=memo.begin();it!=memo.end();it++){
		res.push_back({it->first,it->second});
	}
	sort(res.begin(),res.end(),compare);
	for(int i=0;i<res.size();i++){
		cout << res[i].first << ' ' << res[i].second << endl;
	}
	
	return 0;
}

