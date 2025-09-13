//���������������ͼ���������ڽӱ�洢����
#include <iostream>
#include <vector>
#include <list>
using namespace std;

int n;
int ans=1e9+10;
vector<int> visit(1e6,false);
int dfs(vector<list<int>>& graph,int start){
    visit[start]=true;  //��һ����ɾ��start
    int sum=1; //�������һ���ڵ㣬���Ƿ���1
    int res=0;  //��ǰ���ֿ�����ֵ
    for(auto next :graph[start]){
        if(!visit[next]){
            int curnum=dfs(graph,next);  //��һ����ɾ��next
            sum+=curnum;
            res=max(res,curnum);
        }
    }
    //forѭ��������˵��ɾ��start�Ľڵ���һ�ֽ�����
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
