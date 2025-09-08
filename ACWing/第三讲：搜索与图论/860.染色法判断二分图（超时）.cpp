#include <iostream>
#include <vector>
#include <list>
using namespace std;

const int N=1e5;

vector<bool> visit(N);
vector<bool> color(N,false);
bool ok= true;

void traversal(vector<list<int>> graph,int x){
    if(ok==false) return ;
    visit[x]=true;
    for(auto node :graph[x]){
        if(!visit[node]){
            color[node]=!color[x];
            traversal(graph,node);
        }
        else{
            if(color[node]==color[x]) ok=false;
        }
    }
    return ;
}

int main(){
    int n,m;
    cin >> n >> m;
    vector<list<int>> graph(n+1);
    while(m--){
        int a,b;
        cin >> a >>b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    for(int i=1;i<=n;i++){
        if(!visit[i]){
            traversal(graph,i);
            visit[i]=true;
        }
        if(ok==false) break;
    }
    if(ok) cout << "Yes" << endl;
    else cout << "No" << endl;
    
    return 0;
}

