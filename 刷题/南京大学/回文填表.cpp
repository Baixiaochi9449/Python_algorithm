//找到一个字符，检查同一行/列有没有障碍物，没有，就把对称位置填上相同的
//遍历完一整张图之后，把所有的空位填上一个字符 
//m列， 同一行 [i][j]的对称位置是[i][m-1-j]
#include <iostream>
#include <vector>
#include <string>
using namespace std;
int n,m;

void dfs(vector<vector<char> >& graph,int x,int y,vector<vector<bool> >& visit){
	if(visit[x][y]) return ;
	visit[x][y]=true;
	int up=0,down=n-1; 
	for(int i=x;i>=0;i--){ //往上找 
		if(graph[i][y]=='#'){
			up=i+1; 
			break;
		}
	}
	for(int i=x;i<n;i++){ //往下找 
		if(graph[i][y]=='#'){
			down=i-1;
			break;
		}
	}
	//纵向的对称位置
	int nextx=up+down-x;
	graph[nextx][y]=graph[x][y];
	dfs(graph,nextx,y,visit);
	
	int left=0,right=m-1;
	for(int j=y;j>=0;j--){
		if(graph[x][j]=='#'){
			left=j+1;
			break;
		}
	} 
	for(int j=y;j<m;j++){
		if(graph[x][j]=='#'){
			right=j-1;
			break;
		}
	}
	int nexty=left+right-x;
	graph[x][nexty]=graph[x][y];
	dfs(graph,x,nexty,visit);
	
	return ;
}

int main(){
	
	cin >> n >>m;
	vector<vector<char> > graph(n,vector<char>(m));

	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin >> graph[i][j];
		}
	}
	
	vector<vector<bool> > visit(n,vector<bool>(m,false));
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(graph[i][j]=='.') continue;
			if(graph[i][j]=='#') continue;
			dfs(graph,i,j,visit);
		}
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(graph[i][j]=='.'){
				cout << 'a' << ' ';	
			}
			else 
			cout << graph[i][j] << ' ';
		}
		cout << endl;
	}
	return 0;
}

