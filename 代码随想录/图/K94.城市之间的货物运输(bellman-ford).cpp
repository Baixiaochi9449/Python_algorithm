//bellman-ford
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//把边，权值，存到一个vecotor中，然后遍历n-1次，每次遍历就更新dist[i]
const int INF=1e9;
struct Edge{
    int a,b,val;
};
int main(){
    int n,m;
    cin >> n >>m;
    vector<Edge> edges;
    while(m--){
        int a,b,val;
        cin >> a >> b >> val;
        edges.push_back({a,b,val});
    } 
    vector<int> mindist(n+1,INF);
    mindist[1]=0;
    //遍历n-1次
    for(int i=0;i<n-1;i++){
        for(auto edge:edges){
            if(mindist[edge.a]!=INF){  //已经被赋值了
                if(mindist[edge.b]>mindist[edge.a]+edge.val){
                    mindist[edge.b]=mindist[edge.a]+edge.val;
                }
            }
        }
    }
    if(mindist[n]==INF) cout << "unconnected" << endl;
    else cout << mindist[n] << endl;
    return 0;
}