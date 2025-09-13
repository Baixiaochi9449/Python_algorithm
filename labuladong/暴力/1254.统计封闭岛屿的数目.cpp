class Solution {
    private:
        vector<vector<int>> dir;
        void dfs(vector<vector<int>>& grid,int x ,int y){
            //在前面判断是否符合条件，后面就不用判断了
            int n=grid.size();
            int m=grid[0].size();
            if(x<0 || x>=n || y<0 || y>=m) return ;
            if(grid[x][y]==1) return ;
    
            grid[x][y]=1;
            
            for(int i=0;i<4;i++){
                int nextx=x+dir[i][0];
                int nexty=y+dir[i][1];
                dfs(grid,nextx,nexty);
            }
            return ;
        }
    public:
        int closedIsland(vector<vector<int>>& grid) {
            //这个只需要遍历到一个陆地，res++,然后把它周围的陆地都淹没
            int n=grid.size();
            int m=grid[0].size();
            dir={{1,0},{-1,0},{0,1},{0,-1}};
            //先把边缘的地都删了
            for(int i=0;i<n;i++){
                if(grid[i][0]==0) dfs(grid,i,0);
                if(grid[i][m-1]==0)  dfs(grid,i,m-1);
            }
            for(int j=0;j<m;j++){
                if(grid[0][j]==0) dfs(grid,0,j);
                if(grid[n-1][j]==0) dfs(grid,n-1,j);
            }
            //开始找岛屿，在淹没一整个大岛屿的时候，同时计算数量
            int res=0;
            for(int i=0;i<n;i++){
                for(int j=0;j<m;j++){
                    if(grid[i][j]==0){
                        res++;
                        dfs(grid,i,j);
                    }
                }
            }
            return res;
        }
    };