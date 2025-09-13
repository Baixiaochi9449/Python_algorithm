class Solution {
    private:
        vector<vector<int>> dir;
        bool success;
        void dfs(vector<vector<int>>& grid1, vector<vector<int>>& grid2,int x,int y){
            int n=grid1.size();
            int m=grid1[0].size();
            if(x<0 || x>=n || y<0 || y>=m) return ;;
            if(grid2[x][y]==0) return ; 
    
            if(grid2[x][y]==1 && grid1[x][y]==0) success=false;  //  只靠这个判断所有都错
    
            grid2[x][y]=0;  //遍历过了，之间变海洋
            for(int i=0;i<4;i++){
                int nextx=x+dir[i][0];
                int nexty=y+dir[i][1];
    
                // if(nextx<0 || nextx>=n || nexty<0 || nexty>=m) continue;
                // if(grid2[nextx][nexty]==0) continue;
    
                dfs(grid1,grid2,nextx,nexty);
            }
            return ;
        }
    public:
        int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
            //遍历grid2中的每个位置，开始处理一整个岛屿，返回值为true,
            int n=grid1.size();
            int m=grid1[0].size();
            int res=0;
            dir={{1,0},{-1,0},{0,1},{0,-1}};
            for(int i=0;i<n;i++){
                for(int j=0;j<m;j++){
                    if(grid2[i][j]==1){
                        success=true;
                        dfs(grid1,grid2,i,j);
                        if(success) res++;
                    }
                }
            }
            return res;
        }
    };