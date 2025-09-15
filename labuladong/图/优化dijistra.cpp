#include <iostream>
#include <vector>
#include <queue>
#include <list>
using namespace std;

const int INF=1e9;

int main(){
	int n,m;
	cin >> n >> m;  //n个点  m个边  点从1开始
	vector<list<pair<int,int> > > graph(n+1);
	for(int i=0;i<m;i++){
		int a,b,v; 
		cin >> a >> b >> v;
		//这样就难以处理重边情况了，默认没有重边
		graph[a].push_back({v,b});  //第一个值是权重，第二个是指向的点 
	} 
	vector<bool> visit(n+1,false);
	vector<int> mindist(n+1,INF); 
	mindist[1]=0;
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> que;
	que.push({0,1}); //把1放进去
	visit[1]=true;
	while(!que.empty()){
		pair<int,int> cur=que.top();
		que.pop();
		int curnode=cur.second;
		int curdist=cur.first;
		visit[curnode]=true;  //要在弹出的时候标记已经访问，而不是 加入的时候
		for(pair<int,int> next :graph[curnode]){
			int nextnode=next.second;
			int nextdist=next.first;
			if(visit[nextnode]) continue;
// 			visit[nextnode]=true;  对于优先级队列，同一个节点可能会被多次加入队列（通过不同路径），但只有第一次弹出时才是最短路径
			if(mindist[nextnode]>nextdist+curdist){
				mindist[nextnode]=nextdist+curdist;
				que.push({mindist[nextnode],nextnode});
			}
		}
	} 
	if(mindist[n]==INF) cout << -1 << endl;
	else cout << mindist[n] << endl;
	
	return 0;
}
