#include <iostream>
#include <vector>
#include <string>
using namespace std;

void dfs(vector<vector<char> >& graph,int x,int y ){
	int n=graph.size();
	int m=graph[0].size();
	if(x<0 || x>=n || y<0 || y>=m) return ;
	if(graph[x][y]=='.') return ;
	
	graph[x][y]='.';
	
	dfs(graph,x,y-1);
	dfs(graph,x-1,y);
	dfs(graph,x-1,y-1);
    dfs(graph,x+1,y);
    dfs(graph,x,y+1);
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
	
	int res=0;
	//只能从右下角开始 
	for(int i=n-1;i>=0;i--){
		for(int j=m-1;j>=0;j--){
			if(graph[i][j]=='x'){
				res++;
				dfs(graph,i,j);
			}
		}
	}
	cout << res << endl;
	return 0;
} 
