//用mindist存放起点到某个节点的最短距离，  minedge存放从起点到某个节点的最短的边,初始化为0
//如果用链表，不能处理重边情况，所以改用矩阵 
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

const int INF=1e9;

int main(){
	int n,m,k;
	cin >> n >> m >> k;  //n个点 ，从1开始的
	vector<vector<int>> graph(n+1,vector<int>(n+1,INF));
	for(int i=0;i<m;i++){
		int a,b,v;
		cin >> a >> b >> v;
		graph[a][b]=min(graph[a][b],v);  //有向图 
	}
	
	vector<bool> visit(n+1,false);
	visit[1]=true;
	
	priority_queue<pair<int,int>,vector<pair<int,int>> ,greater<pair<int,int>> > que;   //默认取最大值 
	que.push({0,1});  //节点 和mindist[node] 的值   //应该先存储节点
	
	vector<int> mindist(n+1,INF);
	mindist[1]=0;
	vector<int> edges(n+1,0);  //更新最短距离的时候要更新边数
	
	while(!que.empty()){
		auto cur=que.top();
		que.pop();
		int curnode=cur.second;
		int curval=cur.first;
		visit[curnode]=true;  //出队的时候变为true
		
		for(int i=1;i<=n;i++){
			if(visit[i]) continue;
			if(graph[curnode][i]==INF) continue; //不连通 
			if(mindist[i] > graph[curnode][i]+curval){
				mindist[i] = graph[curnode][i]+curval;
				edges[i]=edges[curnode]+1; 
				if(edges[i]<k){ //就加入队列 
					que.push({mindist[i],i}); 
				}
			}
		} 
		
	} 
	if(mindist[n]==INF) cout << "impossible" << endl;
	else  cout << mindist[n] << endl;
	
} 
 
