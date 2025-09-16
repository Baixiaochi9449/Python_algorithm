//��mindist�����㵽ĳ���ڵ����̾��룬  minedge��Ŵ���㵽ĳ���ڵ����̵ı�,��ʼ��Ϊ0
//������������ܴ����ر���������Ը��þ��� 
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

const int INF=1e9;

int main(){
	int n,m,k;
	cin >> n >> m >> k;  //n���� ����1��ʼ��
	vector<vector<int>> graph(n+1,vector<int>(n+1,INF));
	for(int i=0;i<m;i++){
		int a,b,v;
		cin >> a >> b >> v;
		graph[a][b]=min(graph[a][b],v);  //����ͼ 
	}
	
	vector<bool> visit(n+1,false);
	visit[1]=true;
	
	priority_queue<pair<int,int>,vector<pair<int,int>> ,greater<pair<int,int>> > que;   //Ĭ��ȡ���ֵ 
	que.push({0,1});  //�ڵ� ��mindist[node] ��ֵ   //Ӧ���ȴ洢�ڵ�
	
	vector<int> mindist(n+1,INF);
	mindist[1]=0;
	vector<int> edges(n+1,0);  //������̾����ʱ��Ҫ���±���
	
	while(!que.empty()){
		auto cur=que.top();
		que.pop();
		int curnode=cur.second;
		int curval=cur.first;
		visit[curnode]=true;  //���ӵ�ʱ���Ϊtrue
		
		for(int i=1;i<=n;i++){
			if(visit[i]) continue;
			if(graph[curnode][i]==INF) continue; //����ͨ 
			if(mindist[i] > graph[curnode][i]+curval){
				mindist[i] = graph[curnode][i]+curval;
				edges[i]=edges[curnode]+1; 
				if(edges[i]<k){ //�ͼ������ 
					que.push({mindist[i],i}); 
				}
			}
		} 
		
	} 
	if(mindist[n]==INF) cout << "impossible" << endl;
	else  cout << mindist[n] << endl;
	
} 
 
