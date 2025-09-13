class Solution {
    private:
        vector<vector<int>> dir;
        void dfs(vector<vector<char>>& grid,int x ,int y){
            //在前面判断是否符合条件，后面就不用判断了
            int n=grid.size();
            int m=grid[0].size();
            if(x<0 || x>=n || y<0 || y>=m) return ;
            if(grid[x][y]=='0') return ;
    
            grid[x][y]='0';
            
            for(int i=0;i<4;i++){
                int nextx=x+dir[i][0];
                int nexty=y+dir[i][1];
                dfs(grid,nextx,nexty);
            }
            return ;
        }
    public:
        int numIslands(vector<vector<char>>& grid) {
            int n=grid.size();
            int m=grid[0].size();
            dir={{1,0},{-1,0},{0,1},{0,-1}};
            int res=0;
            for(int i=0;i<n;i++){
                for(int j=0;j<m;j++){
                    if(grid[i][j]=='1'){
                        res++;
                        dfs(grid,i,j);
                    }
                }
            }
            return res;
        }
    };