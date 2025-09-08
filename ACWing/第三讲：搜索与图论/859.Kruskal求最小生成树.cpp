#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int N=1e6+10;

vector<int> father(N);

void init(){
    for(int i=0;i<N;i++){
        father[i]=i;
    }
}

int find(int x){
    if(x==father[x]) return x;
    else{
        father[x]=find(father[x]);
        return father[x];
    }
}

bool isSame(int x,int y){
    x=find(x);
    y=find(y);
    if(x==y) return true;
    else return false;
}

void join(int x,int y){
    x=find(x);
    y=find(y);
    if(x!=y){
        father[y]=x;
    } 
}

struct Edge{
    int a,b,val;
};

bool compare(Edge& a,Edge& b){
    return a.val<b.val;
}

int main(){
    int n,m;
    cin >> n >> m;
    vector<Edge> edges(m);
    for(int i=0;i<m;i++){
        int a,b,val;
        cin >> a >> b >> val;
        edges[i]={a,b,val};
    }
    
    sort(edges.begin(),edges.end(),compare);
    init();
    int res=0;
    int ct=0;
    for(auto edge :edges){
        if(!isSame(edge.a,edge.b)){
            res+=edge.val;
            join(edge.a,edge.b);
            ct++;
        }
    }
    if(ct!=n-1) cout << "impossible" << endl;
    else cout << res << endl;
    return 0;
}