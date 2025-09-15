class Solution {
private:
    bool iscycle=false;

    vector<bool> onpath;  //存储i到j的这条边是否已经走过了
    void dfs(vector<vector<int>>& graph,int x){
        // visit[x]=true;  //就统一写在这个位置吧，不然写2个位置，尤其是传进来的那个位置，容易忘记
        if(iscycle==true) return ;
        onpath[x]=true;
        for(auto node :graph[x]){
            // if(visit[node]) continue;
            if(onpath[node]){
                iscycle=true;
                return ;
            }
             onpath[node]=true;
            dfs(graph,node);
            onpath[node]=false;
        }
    }
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        //边检测，遍历每一条边，如果重复遍历了，说明就成环了。
        //这种方法复杂度较高，但是为了熟悉一遍 遍历边
        onpath=vector<bool>(numCourses,false);
        // visit=vector<bool>(numCourses,false);
        vector<vector<int>> graph(numCourses);
        for(auto cur : prerequisites){
            int a=cur[0];
            int b=cur[1];
            graph[b].push_back(a);
        }
        for(int i=0;i<numCourses;i++){
            // if(visit[i]) continue;
            onpath[i]=true;
            dfs(graph,i);
            onpath[i]=false;
            if(iscycle) break;
        }
        if(iscycle) return false;
        else return true;
    }
};
