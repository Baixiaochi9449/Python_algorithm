#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int INF=1e9;  //初始化一个最大值

int main(){
    int n,m,q;
    cin >> n >> m >> q;
    vector<vector<int>> graph(n+1,vector<int>(n+1,INF));
    //初始化：自己到自己的距离为0
    for(int i=1;i<=n;i++){
        graph[i][i]=0;
    }
    while(m--){
        int a,b,val;
        cin >> a>> b >> val;
        graph[a][b]=min(graph[a][b],val);
    }
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                graph[i][j]=min(graph[i][k]+graph[k][j],graph[i][j]);
            }
        }
    }
    while(q--){
        int a,b;
        cin >> a >>b;
        if(graph[a][b]>INF/2) cout << "impossible" << endl;    //INF/2是为了考虑负边情况
        else cout << graph[a][b]  << endl;
    }
    return 0;
}