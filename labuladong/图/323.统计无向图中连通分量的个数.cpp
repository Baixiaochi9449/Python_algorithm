//����ͼ����ͨ����---���鼯������һ���ߣ���join .������һ��ÿ���ڵ�����ȣ��洢set�У���Ϊset�Զ�ȥ�أ�����set�Ĵ�С
//father�кܶ࣬��������ֻ��һ��
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
	cin >> n >> m;    //m���� 
	
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
