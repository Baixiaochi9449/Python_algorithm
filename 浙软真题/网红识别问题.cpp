//��¼���� ���>=2   ����ע�Լ���ָ�������û���Լ����ѹ�ע���˴洢��list��
#include <iostream>
#include <list>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
	int n,m,t;
	cin >> n >> m >> t;
	vector<list<int> > graph(n+1); //��1��ʼ�� 
	vector<int> indegree(n+1,0);
	for(int i=0;i<m;i++){
		int a,b;
        cin >> a >> b;
		graph[a].push_back(b);
		indegree[b]+=1; 
	}
    // cout << "2�ķ�˿��" << indegree[2] << endl;
	vector<int> res;
	for(int i=1;i<=n;i++){
		if(indegree[i]>=t){ //���������� 
			bool success=true;
			for(int node : graph[i]){
				//����graph[node]���Ƿ���i
				for(int tar :graph[node]){
					if(tar==i){
						success=false;
						break;
					}
				}
				if(success==false) break;	 
			} 
			if(success) res.push_back(i);
		}
	}
	
	sort(res.begin(),res.end());
    if(res.size()==0) cout <<"None" << endl;
    else{
        for(int i=0;i<res.size();i++){
            cout << res[i] << ' ';
        }
    }

	return 0;
}
 
