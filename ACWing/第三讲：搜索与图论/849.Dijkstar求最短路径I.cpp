//1--n的最短距离，可否直接用bfs？ 不可以！！bfs可以求步数最少，而不是距离最短
//思路：1加入node节点集，初始化mindist[] 全都是距离1的距离。 2.选取距离1最近的节点，加入节点集，然后更新mindist. 比较规则为 minsidt[i]>minsidt[node]+graph[node][i]
//有向图，有边长，需要用邻接矩阵
//还有一个set集合，表示已经在集合里面了
#include <iostream>
#include <vector>
#include <list>
#include <set>
using namespace std;
int INF = 1e9+10;
int main(){
    int n,m;
    cin >> n >> m;
    vector<vector<int>> graph(n+1,vector<int>(n+1,INF));
    vector<int> mindist(n+1,INF);
    set<int> used;
    while(m--){
        int a,b,l;
        cin >> a >> b >> l;
        graph[a][b]=min(graph[a][b],l);  //处理重边！！！
    }
    //初始化 并找到距离1最近的点
    used.insert(1);
    for(int i=2;i<n+1;i++){
        if(graph[1][i]!=INF){
            mindist[i]=graph[1][i];
        }
    }
    //找最近的点，加入并更新的过程要重复 n次?
    for(int k=0;k<n-1;k++){
        int min_node;
        int min_value=INF;
        for(int i=2;i<n+1;i++){
            if(used.find(i)==used.end() && min_value>mindist[i]){
                min_value=mindist[i];
                min_node=i;
            }
        }
        used.insert(min_node);
        for(int i=2;i<n+1;i++){
            if(used.find(i)==used.end() && mindist[i]>graph[min_node][i]+mindist[min_node]){
                mindist[i]=graph[min_node][i]+mindist[min_node];
            }
        }
    }
    if(mindist[n]==INF) cout << -1 << endl;
    else cout << mindist[n] << endl;
    return 0;
}
