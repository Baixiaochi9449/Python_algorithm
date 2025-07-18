#include <iostream>
#include <vector>
using namespace std;

int MAX=100;
vector<int> father(MAX);
void init(){
    for(int i=0;i<MAX;i++){
        father[i]=i;
    }
}
int Find(int x){
    if(x==father[x]) return x;
    else{
        father[x]=Find(father[x]);
        return father[x];
    }
}
void join(int x,int y){
    x=Find(x);
    y=Find(y);
    if(x!=y){
        father[y]=x;
    }
}
bool isSame(int x,int y){
    x=Find(x);
    y=Find(y);
    if(x==y) return true;
    else return false;
}

bool isTreeAfterdelete(vector<vector<pair<int,int>>> graph,pair<int,int> e,int n){
    init();
    for(int i=1;i<=n;i++){
        for(pair<int,int> edge : graph[i]){
            if(edge==e) continue;
            if(isSame(edge.first,edge.second)){
                return false;
            }
            else{
                join(edge.first,edge.second);
            }
        }
    }
    return true;
}

int main(){
    int n;
    while(cin >> n){
        vector<vector<pair<int,int>>> graph(n+1);
        vector<int> indegree(n+1,0);
        for(int i=0;i<n;i++){
            int s,t;
            cin >> s >> t;
            indegree[t]++;
            graph[t].push_back({s,t});  //把入度的点 连接的边，存放
        }

        //找到入度==2的点
        int target=-1;
        for(int i=1;i<=n;i++){
            if(indegree[i]==2){
                target=i;
            }
        }
        if(target!=-1){ //存在入度为2的点
            auto fi=graph[target][0];
            auto se=graph[target][1];
            if(isTreeAfterdelete(graph,fi,n)){
                cout << fi.first << " " << fi.second << endl;
            }
            else{
                cout << se.first << " " << se.second << endl;
            }
        }
        else{  //并查集
            init();
            for(int i=1;i<=n;i++){
                for(auto edge : graph[i]){
                    if(isSame(edge.first,edge.second)){
                        cout << edge.first <<" " << edge.second << endl;
                    }
                    else{
                        join(edge.first,edge.second);
                    }
                }
            }
        }
    }
    return 0;
}