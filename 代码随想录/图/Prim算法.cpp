#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

int main(){
    int n,m;
    while(cin >> n >> m){
        vector<vector<int>> graph(n+1,vector<int>(n+1,1000));
        while(m--){
            int i,j,v;
            cin >> i >> j >> v;
            graph[i][j]=v;
            graph[j][i]=v;
        }
        vector<int> minDist(n+1);
        unordered_set<int> visit;
        visit.insert(1);
        for(int i=2;i<=n;i++){
            minDist[i]=graph[1][i];
        }

        //重复n-1次？？为什么
        for(int k=0;k<n-1;k++){
            //第一步：找到距离节点 最小的非节点
            int cur;
            int min=1000;
            for(int i=2;i<=n;i++){
                if(visit.count(i)) continue;
                if(minDist[i]<min){
                    min=minDist[i];
                    cur=i;
                }
            }
            //第二部：加入到set中
            visit.insert(cur);
            //第三步，更新minDist
            for(int i=2;i<=n;i++){
                if(visit.count(i)) continue; //这里也不能更新已经加入的
                if(minDist[i]>graph[i][cur]){
                    minDist[i]=graph[i][cur];
                }
            }
        }
        
        int sum=0;
        for(int i=2;i<=n;i++){
            sum+=minDist[i];
        }
        cout << sum << endl;

    }
}