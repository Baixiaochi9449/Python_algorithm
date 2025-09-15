//无向图，连通分量---并查集，读入一条边，就join .最后遍历一下每个节点的祖先，存储set中，因为set自动去重，计算set的大小
//father有很多，但是祖先只有一个
#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

vector<int> father(1000);
void init(){
	for(int i=0;i<1000;i++){
		father[i]=i;
	}
}

int find(int x){
	if(father[x]==x) return x;
	else{
		father[x]=find(father[x]);
		return father[x];
	}	
}

void join(int x,int y){
	x=find(x);
	y=find(y);
	if(x==y) return;
	else{
		father[y]=x;
	}
}


int main(){
	init();
	int n,m;
	cin >> n >> m;    //m条边 
	
	for(int i=0;i<m;i++){
		int a,b;
		cin >> a >> b;
		join(a,b);
	} 
	
	set<int> memo;
	for(int i=0;i<n-1;i++){
		int x=find(i);
		memo.insert(x);
	}
	int res=memo.size();
	cout << res << endl;
	return 0;
} 
