class Solution {
private:
    bool iscycle=false;

    vector<bool> onpath;  //�洢i��j���������Ƿ��Ѿ��߹���
    void dfs(vector<vector<int>>& graph,int x){
        // visit[x]=true;  //��ͳһд�����λ�ðɣ���Ȼд2��λ�ã������Ǵ��������Ǹ�λ�ã���������
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
        //�߼�⣬����ÿһ���ߣ�����ظ������ˣ�˵���ͳɻ��ˡ�
        //���ַ������ӶȽϸߣ�����Ϊ����Ϥһ�� ������
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
