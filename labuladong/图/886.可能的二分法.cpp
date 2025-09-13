//这两个互不喜欢的就是一条边，一条边的两个点不能一样
class Solution {
    private:
        bool ok=true;
        vector<int> color; 
        void dfs(vector<list<int>>& graph,int x){
            for(auto node:graph[x]){
                if(color[node]==0){
                    color[node]=(-1)*color[x];
                    dfs(graph,node);
                }
                else{
                    if(color[node]==color[x]) ok=false;
                }
            }
        }
    public:
        bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
            //构造图
            color=vector<int>(n+1,0); //都没有染色
            vector<list<int>> graph(n+1);
            for(auto pair : dislikes){
                int x=pair[0];
                int y=pair[1];
                graph[x].push_back(y);
                graph[y].push_back(x);
            }
            //从每个节点开始，遍历图 .因为图可能不连通
            for(int i=1;i<=n;i++){
                if(color[i]==0){
                    color[i]=1;
                    dfs(graph,i);
                }
                if(ok==false) return false;
            }
            return true;
        }
    };