//求节点1 到n 的最短距离， 
//定义一个mindist数组，初始化为1到各个节点的距离。
//visit(boo) 数组记录已经加入的节点
// 初始化找到距离1最近的节点，加入队列
//处理当前节点， 更新dist数组，再加入一个最近的节点

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

const int INF=1e9; //这个最大数，越大越好 

int main(){
	int n,m;
	cin >> n >> m;
	vector<vector<int> > graph(n+1,vector<int>(n+1,INF)); //初始为-1，表示不可达
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
