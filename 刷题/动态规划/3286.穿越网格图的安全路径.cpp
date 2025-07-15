//深搜会stackooverflow, 用 广搜 +dp
//dp的意思是，到i，j这个位置的时候的最大健康值
class Solution {
public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> dp(n,vector<int>(m,0));
        vector<vector<int>> dir={{0,-1},{0,1},{1,0},{-1,0}};
        queue<pair<int,int>> que;
        dp[0][0]=health-grid[0][0];
        if(dp[0][0]<=0) return false;
        que.push({0,0});
        //开始广搜
        while(!que.empty()){
            auto pos=que.front();
            que.pop();
            int x=pos.first;
            int y=pos.second;
            for(int i=0;i<4;i++){
                int nextx=x+dir[i][0];
                int nexty=y+dir[i][1];
                if(nextx<0 || nextx>=n || nexty<0 || nexty>=m) continue;
                int newhealth=dp[x][y]-grid[nextx][nexty];
                if(newhealth>dp[nextx][nexty]){
                    dp[nextx][nexty]=newhealth;  //只有比之前大，才更新，如果没有更新，依然把next,nexty还继续压进去，会一直循环下去。 只有比之前大&&并且>0, 才把它压进去， 压进去的数字都是要走的路径 
                    if(dp[nextx][nexty]>0){
                        que.push({nextx,nexty});
                    }
                }
            }
        }
        return dp[n-1][m-1]>0;
    }
};  