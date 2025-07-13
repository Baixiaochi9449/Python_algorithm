//不能用并查集。
//本题为，保证图为 有向无环图（环是能回到自己的环）--->拓扑排序
//广度优先搜索： 存储2：1  学2之前要学1.  3：1 学3之前要学1 
class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> edges(numCourses);
        vector<int> indegree(numCourses,0);
        queue<int> que;
        vector<int> visit(numCourses,0); 
        for(int i=0;i<prerequisites.size();i++){
            edges[prerequisites[i][1]].push_back(prerequisites[i][0]);
            indegree[prerequisites[i][0]]++;
        }
        for(int i=0;i<numCourses;i++){
            if(indegree[i]==0) {
                que.push(i);
                visit[i]=1;
            }
        }
        while(!que.empty()){
            int cur=que.front();
            que.pop();
            for(int j=0;j<edges[cur].size();j++){
                indegree[edges[cur][j]]--;
            }
            for(int i=0;i<numCourses;i++){
                if(indegree[i]==0 && !visit[i]) {
                    que.push(i);
                    visit[i]=1;
                }
            }

        }
        for(int i=0;i<numCourses;i++){
            if(indegree[i]>0) return false;
        }
        return true;
    }
};