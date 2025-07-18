//邻接表存储， 深搜----》深搜超时了
//试试广搜
class Solution {
private:
    vector<bool> visit=vector<bool>(1000,false);
    bool dfs(vector<list<int>> graph,int s,int d){
        for(int node : graph[s]){
            if(visit[node]) continue;
            if(node==d) return true;
            else{
                visit[node]=true;
                if(dfs(graph,node,d)){
                    return true;
                }
                else{
                    visit[node]=false;
                }
            }
        }
        return false;
    }
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<list<int>> graph(n);
        if(edges.size()==0) return true;
        for(vector<int> edge : edges){
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }
        if(dfs(graph,source,destination)){
            return true;
        }
        else return false;
    }
};

//邻接表存储， 深搜----》深搜超时了
//试试广搜
class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<list<int>> graph(n);
        vector<bool> visit(n,false);
        if(edges.size()==0) return true;
        for(vector<int> edge : edges){
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }
        queue<int> que;
        que.push(source);
        while(!que.empty()){
            int cur=que.front();
            que.pop();
            visit[cur]=true;
            if(cur==destination) return true;
            for(int node : graph[cur]){
                if(node==destination) return true;
                if(visit[node]) continue;
                que.push(node);
                visit[node]=true;
            }
        }
        return false;
    }
};