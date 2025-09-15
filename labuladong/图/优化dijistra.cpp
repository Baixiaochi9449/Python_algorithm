#include <iostream>
#include <vector>
#include <queue>
#include <list>
using namespace std;

const int INF=1e9;

int main(){
	int n,m;
	cin >> n >> m;  //n����  m����  ���1��ʼ
	vector<list<pair<int,int> > > graph(n+1);
	for(int i=0;i<m;i++){
		int a,b,v; 
		cin >> a >> b >> v;
		//���������Դ����ر�����ˣ�Ĭ��û���ر�
		graph[a].push_back({v,b});  //��һ��ֵ��Ȩ�أ��ڶ�����ָ��ĵ� 
	} 
	vector<bool> visit(n+1,false);
	vector<int> mindist(n+1,INF); 
	mindist[1]=0;
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> que;
	que.push({0,1}); //��1�Ž�ȥ
	visit[1]=true;
	while(!que.empty()){
		pair<int,int> cur=que.top();
		que.pop();
		int curnode=cur.second;
		int curdist=cur.first;
		visit[curnode]=true;  //Ҫ�ڵ�����ʱ�����Ѿ����ʣ������� �����ʱ��
		for(pair<int,int> next :graph[curnode]){
			int nextnode=next.second;
			int nextdist=next.first;
			if(visit[nextnode]) continue;
// 			visit[nextnode]=true;  �������ȼ����У�ͬһ���ڵ���ܻᱻ��μ�����У�ͨ����ͬ·��������ֻ�е�һ�ε���ʱ�������·��
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
