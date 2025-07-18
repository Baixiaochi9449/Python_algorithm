#include <iostream>
#include <vector>
#include <list>
#include <queue>
using namespace std;

int main(){
    int n,m;
    while(cin >> n >> m){
        vector<list<int>> graph(n);
        vector<int> indegree(n,0);
        while(m--){
            int s,t;
            cin >> s >> t;
            indegree[t]++;
            graph[s].push_back(t);
        }

        queue<int> que;
        for(int i=0;i<n;i++){
            if(indegree[i]==0){
                que.push(i);
            }
        }
        vector<int> result;
        while(!que.empty()){
            int cur=que.front();
            que.pop();
            result.push_back(cur);

            for(int x :graph[cur]){
                indegree[x]--;
                if(indegree[x]==0){
                    que.push(x);
                }
            }
        }
        if(result.size()<n) {
            cout << -1 << endl;
        }
        else{
            for(int i=0;i<n;i++){
                if(i==n-1){
                    cout << result[i]<< endl;
                }
                else cout << result[i] <<" ";
            }
        }
    }
    return 0;
}