//图中不存在环，就不需要用onpath数组，和visit
class Solution {
private:
    vector<vector<int>> res;
    vector<int> path;
    void dfs(vector<vector<int>>& graph,int x){
        int n=graph.size();
        if(x==n-1){
            res.push_back(path);
            return ;
        }
        for(int node : graph[x]){
            path.push_back(node);
            dfs(graph,node);
            path.pop_back();
        }
        return ;
    }
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        path.push_back(0);
        dfs(graph,0);
        return res;
    }
};
