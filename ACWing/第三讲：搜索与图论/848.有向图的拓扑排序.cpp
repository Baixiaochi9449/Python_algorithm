//有向图：拓扑排序   无向图：并查集
//queue队列， indegree数组， graph
#include <iostream>
#include <queue>
#include <vector>
#include <list>
using namespace std;

int main(){
    int n,m;
    cin >> n >> m;
    vector<int> indegree(n+1,0);
    vector<list<int>> graph(n+1);
    while(m--){
        int a,b;
        cin >> a >> b;
        indegree[b]++;
        graph[a].push_back(b);
    }
    queue<int> que;
    vector<int> res;
    //寻找入度为0的点加入队列
    for(int i=1;i<n+1;i++){
        if(indegree[i]==0){
            que.push(i);
        }
    }
    while(!que.empty()){
        int cur=que.front();
        que.pop();
        res.push_back(cur);
        for(auto node :graph[cur]){
            indegree[node]--;
            if(indegree[node]==0){
                que.push(node);
            }
        }
    }
    if(res.size()==n){
        for(int i=0;i<res.size();i++){
            cout << res[i] << ' ';
        }
    }
    else cout << -1;
    return 0;
}
