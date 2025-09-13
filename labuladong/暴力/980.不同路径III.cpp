class Solution {
    private:
        vector<vector<int>> dir;
        vector<vector<bool>> visit;
        vector<int> pos1;
        vector<int> pos2;
        int res=0;
        int empty_cont;
        void backtracking(vector<vector<int>>& grid,int x,int y,int cont){
            if(x==pos2[0] && y==pos2[1]){
                if(cont==empty_cont+1) res++;
                return ;
            }
            int n=grid.size();
            int m=grid[0].size();
            for(int i=0;i<4;i++){
                int nextx=x+dir[i][0];
                int nexty=y+dir[i][1];
                if(nextx<0 || nextx>=n || nexty<0 || nexty>=m) continue;
                if(visit[nextx][nexty]) continue;
                if(grid[nextx][nexty]==-1) continue;
                visit[nextx][nexty]=true;
                backtracking(grid,nextx,nexty,cont+1);
                visit[nextx][nexty]=false;
            }
            return ;
        }
    public:
        int uniquePathsIII(vector<vector<int>>& grid) {
            dir={{-1,0},{1,0},{0,1},{0,-1}};
            int n=grid.size();
            int m=grid[0].size();
            visit=vector<vector<bool>>(n,vector<bool>(m,false));
            //首先找到1和2的位置 //要统计空方格的个数
            empty_cont=0;
            for(int i=0;i<n;i++){
                for(int j=0;j<m;j++){
                    if(grid[i][j]==1){
                        pos1.push_back(i);
                        pos1.push_back(j);
                    }
                    if(grid[i][j]==2){
                        pos2.push_back(i);
                        pos2.push_back(j);
                    }
                    if(grid[i][j]==0) empty_cont++;
                }
            }
            visit[pos1[0]][pos1[1]]=true;
            backtracking(grid,pos1[0],pos1[1],0);
            return res;
        }
    };