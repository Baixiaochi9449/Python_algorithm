//����
//ÿ��2��ѡ��2�ֵ�ѡ������2�����µݹ�����
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int res=1e9;
void backtracking(vector<vector<char> > graph,int x,int y,int dir,int cont){
	int n=graph.size();
	int m=graph[0].size();
	if(x<0 || x>=n || y<0 || y>=m) return ;
	if(graph[x][y]=='x') return ;
	
	if(x==0 && y==0){
		res=min(res,cont);
		return ;
	}
	
	
	if(dir==0){ //ԭ������ 
		backtracking(graph,x,y-1,0,cont);  //������
		backtracking(graph,x-1,y,1,cont+1);  //������
	}
	else{ //ԭ������ 
		backtracking(graph,x,y-1,0,cont+1);
		backtracking(graph,x-1,y,1,cont); 
	} 
	return ;
	
}

int main(){
	int n,m;
	cin >> n >> m;
	vector<vector<char> > graph(n,vector<char>(m));
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin >> graph[i][j];
		}
	}
	//int dir   0��ʾ��   1��ʾ�ϱ� 
	backtracking(graph,n-1,m-1,0,0);
	if(res!=1e9) cout << res << endl;
	else cout << -1 << endl;
	return 0; 
} 

//һ����������������������-1����� 
