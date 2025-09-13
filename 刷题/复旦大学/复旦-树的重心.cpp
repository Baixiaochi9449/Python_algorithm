//树就是特殊的有向图，可以用邻接表存储起来
#include <iostream>
#include <vector>
#include <list>
using namespace std;

int n;
int ans=1e9+10;
vector<int> visit(1e6,false);
int dfs(vector<list<int>>& graph,int start){
    visit[start]=true;  //这一轮是删除start
    int sum=1; //对于最后一个节点，就是返回1
    int res=0;  //当前划分块的最大值
    for(auto next :graph[start]){
        if(!visit[next]){
            int curnum=dfs(graph,next);  //这一轮是删除next
            sum+=curnum;
            res=max(res,curnum);
        }
    }
    //for循环结束，说明删除start的节点这一轮结束了
    res=max(res,n-sum);
    ans=min(ans,res);
    return sum;
}

int main(){
    cin >> n;
    vector<list<int>> graph(1e5+10);
    for(int i=0;i<n-1;i++){
        int a,b;
        cin >> a >>b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    dfs(graph,1);
    cout << ans << endl;
    return 0;
}
