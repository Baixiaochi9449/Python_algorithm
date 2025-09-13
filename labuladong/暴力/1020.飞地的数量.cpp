//相当于求，孤岛的面积。 
//遍历边界， 当grid[i][j]==1的时候，如果在边界，把自身visit[][] =true, 然后bfs搜索自己周围的岛屿，把相邻的都变为true 。 
//可以用一个visit,也可以直接把遍历过的陆地全都grid[i][j]=0 遍历过的全都淹掉。
//没错，外层是2个for循环，遍历每个位置，对于每个符合条件的位置，使用dfs, 然后标记
class Solution {
    private:
        vector<vector<int>> dir;
        int dfs(vector<vector<int>>& grid,int x ,int y){
            //在前面判断是否符合条件，后面就不用判断了
            int n=grid.size();
            int m=grid[0].size();
            if(x<0 || x>=n || y<0 || y>=m) return 0;
            if(grid[x][y]==0) return 0;
    
            grid[x][y]=0; //淹没同时计算数量
            int cont=1; //计数
            for(int i=0;i<4;i++){
                int nextx=x+dir[i][0];
                int nexty=y+dir[i][1];
                cont+=dfs(grid,nextx,nexty);
            }
            return cont;
        }
    public:
        int numEnclaves(vector<vector<int>>& grid) {
            int n=grid.size();
            int m=grid[0].size();
            dir={{1,0},{-1,0},{0,1},{0,-1}};
            //先把边缘的地都删了
            for(int i=0;i<n;i++){
                dfs(grid,i,0);
                dfs(grid,i,m-1);
            }
            for(int j=0;j<m;j++){
                dfs(grid,0,j);
                dfs(grid,n-1,j);
            }
            //开始找岛屿，在淹没一整个大岛屿的时候，同时计算数量
            int res=0;
            for(int i=0;i<n;i++){
                for(int j=0;j<m;j++){
                    if(grid[i][j]==1){
                        res+=dfs(grid,i,j);
                    }
                }
            }
            return res;
        }
    };