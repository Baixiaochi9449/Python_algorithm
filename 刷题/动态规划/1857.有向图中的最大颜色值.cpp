//使用拓扑排序，在拓扑排序中处理。 有无环，可以最后判断
//建立图 和 入度表 ，队列
//取入度为0的点，加入队列，把相关的边在入度表上--
//颜色怎么处理？我如何记录颜色？ vector<vector<int>> dp(n, vector<int>(26, 0)); dp[i][c] 表示以节点i结尾的路径中颜色c的最大计数
//有向图的图用什么记录的？ 队列里面存放的是
class Solution {
public:
    int largestPathValue(string colors, vector<vector<int>>& edges) {
        //建立图和入度表
        int n=colors.size();
        int m=edges.size();
        vector<list<int>> graph(n);
        vector<int> indegree(n,0);
        int visited=0;
        for(int i=0;i<m;i++){
            graph[edges[i][0]].push_back(edges[i][1]);
            indegree[edges[i][1]]++;
        }
        //处理颜色--》求最大颜色值--》动态规划
        vector<vector<int>> dp(n,vector<int>(26,0)); 
        //初始化队列 ,同时把颜色值更新一下
        queue<int> que;
        for(int i=0;i<n;i++){
            if(indegree[i]==0){
                que.push(i);
                visited++;
                dp[i][colors[i]-'a']=1;
            }
        }
        //遍历队列
        int maxcolor=0;
        while(!que.empty()){
            int curnode=que.front();
            que.pop();

            //更新当前节点的最大颜色值
            for(int c=0;c<26;c++){
                maxcolor=max(maxcolor,dp[curnode][c]);
            }

            //更新入度表
            for(auto &node : graph[curnode]){
                //对于每种颜色，更新node的计数
                for(int c=0;c<26;c++){
                    if(c==colors[node]-'a'){
                        dp[node][c]=max(dp[node][c],dp[curnode][c]+1);   //递归公式，因为node是由curnode来的
                    }
                    else{
                        dp[node][c]=max(dp[node][c],dp[curnode][c]);
                    }
                }

                indegree[node]--;
                if(indegree[node]==0){
                    que.push(node);
                    visited++;
                }
            }
        }
        if(visited!=n){
            return -1;
        }
        return maxcolor;
    }
};