//��ڵ�1 ��n ����̾��룬 
//����һ��mindist���飬��ʼ��Ϊ1�������ڵ�ľ��롣
//visit(boo) �����¼�Ѿ�����Ľڵ�
// ��ʼ���ҵ�����1����Ľڵ㣬�������
//����ǰ�ڵ㣬 ����dist���飬�ټ���һ������Ľڵ�

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

const int INF=1e9; //����������Խ��Խ�� 

int main(){
	int n,m;
	cin >> n >> m;
	vector<vector<int> > graph(n+1,vector<int>(n+1,INF)); //��ʼΪ-1����ʾ���ɴ�
	for(int i=0;i<m;i++){
		int a,b,v;
		cin >> a >> b >> v;
		graph[a][b]=min(graph[a][b],v); 
	} 
	
	vector<bool> visit(n+1,false);
	visit[1]=true;
	vector<int> mindist(n+1,INF);
	mindist[1]=0;
	
	int minidx;
	int minlen=INF;
	for(int i=2;i<=n;i++){
		mindist[i]=graph[1][i];
		if(graph[1][i]<minlen){
			minlen=graph[1][i];
			minidx=i;
		}
	}
	queue<int> que;
	que.push(minidx);
	visit[minidx]=true;
	
	while(!que.empty()){
		int cur=que.front();
		que.pop();
		int minidx=-1;
		int minlen=INF;
		for(int i=2;i<=n;i++){
			if(visit[i]) continue;
			if(mindist[i]>graph[cur][i]+mindist[cur]){
				mindist[i]=graph[cur][i]+mindist[cur];
			}
			if(mindist[i]<minlen){
				minlen=mindist[i];
				minidx=i;
			}
		}
		if(minidx!=-1){
			que.push(minidx);
			visit[minidx]=true;
		}
	}
	if(mindist[n]!=INF) cout << mindist[n] << endl;
	else cout << -1 << endl;
	return 0;
} 
