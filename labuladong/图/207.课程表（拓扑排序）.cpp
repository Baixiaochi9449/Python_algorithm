class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        //有向图的环的判断
        //首先存储到一个图里  
        vector<vector<int>> graph(numCourses);
        vector<int> indegree(numCourses);
        for(auto cur : prerequisites){
            int a=cur[0];
            int b=cur[1];
            graph[b].push_back(a);
            indegree[a]++;
        }
        //首先把所有入度为0的存放到queue中，然后遍历que中的节点，把它指向的点的入度都--
        queue<int> que;
        for(int i=0;i<numCourses;i++){
            if(indegree[i]==0){
                que.push(i);
            }
        }
        while(!que.empty()){
            int cur=que.front();
            que.pop();
            for(auto node :graph[cur]){
                indegree[node]--;
                if(indegree[node]==0){
                    que.push(node);
                }
            }
        }
        //检查是否还有节点的入度不为0，则存在环
        for(int i=0;i<numCourses;i++){
            if(indegree[i]>0) return false;
        }
        return true;
    }
};
