class Solution {
    private:
        vector<bool> visit; //在这里定义全局变量，在主函数里赋上大小
        vector<bool> color;
        int ok=true;  //判断是否已经不是二分图了
        void traversal(vector<vector<int>>& graph,int x){
            if(ok==false) return ;
            for(auto node :graph[x]){
                if(!visit[node]){
                    color[node]=!color[x];
                    visit[node]=true;
                    traversal(graph,node);
                }
                else{
                    if(color[node]==color[x]) ok=false;
                }
            }
            return ;
        }
    
    
    public:
        bool isBipartite(vector<vector<int>>& graph) {
            int n=graph.size();
            visit = vector<bool>(n);
            color = vector<bool>(n);
            //因为图可能不是联通的，可能存在多个子图，所以需要把n个节点都作为起点遍历一遍
            //如果存在一个子图是false,那么全都是false
            for(int i=0;i<n;i++){
                if(!visit[i]){
                    traversal(graph,i);
                }
                if(ok==false) break;
            }
            return ok;
        }
    };