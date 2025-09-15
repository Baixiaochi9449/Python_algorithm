class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        //����ͼ�Ļ����ж�
        //���ȴ洢��һ��ͼ��  
        vector<vector<int>> graph(numCourses);
        vector<int> indegree(numCourses);
        for(auto cur : prerequisites){
            int a=cur[0];
            int b=cur[1];
            graph[b].push_back(a);
            indegree[a]++;
        }
        //���Ȱ��������Ϊ0�Ĵ�ŵ�queue�У�Ȼ�����que�еĽڵ㣬����ָ��ĵ����ȶ�--
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
        //����Ƿ��нڵ����Ȳ�Ϊ0������ڻ�
        for(int i=0;i<numCourses;i++){
            if(indegree[i]>0) return false;
        }
        return true;
    }
};
