//����ͼ���������ڽӱ�洢
 //dfs, ����ÿ����Ĵ��� 
 //��һ��ȫ�ֱ��� istree ,ֻҪ����ĳ���ڵ��ʱ���Ϊ��false,��ô��No
 //�������Ľڵ�Ҫvisit 
 #include <iostream>
 #include <vector>
 #include <list>
 #include <algorithm>
 using namespace std;
 
 const int N=1e5+10;
 vector<int> color(N);
 vector<bool> visit(N,false);
 bool istrue=true;
 
 void dfs(vector<vector<int> >& graph,int x){
	visit[x]=true;
	for(int k=0;k<graph[x].size();k++){
		int node=graph[x][k];
 		if(visit[node]){
 			if(color[node]==color[x]) istrue=false;
		 }
		else{
			color[node]=(-1)*color[x];
			dfs(graph,node); 
		}
	}
 }
 
 int main(){
	int n,m;
	cin >> n >> m;  //n����   m����
	vector<vector<int> > graph(n+1); //��1��ʼ�� 
	for(int i=0;i<m;i++){
		int a,b;
		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a); 
	}
	
	for(int i=1;i<=n;i++){
		if(!visit[i]){
			color[i]=1;  //ÿ�����ڵ�ͿɫΪ1 
			dfs(graph,i);
		}
		if(istrue==false) break;
		 
	}
	if(istrue) cout << "Yes" << endl;
	else cout << "No" << endl;
	return 0;
 } 
