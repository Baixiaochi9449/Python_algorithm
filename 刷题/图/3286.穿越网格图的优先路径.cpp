//回溯 
//超出时间限制了，如何剪枝？
class Solution {
private:
    vector<vector<int>> dir={{0,1},{0,-1},{1,0},{-1,0}};
    bool backtracking(vector<vector<int>>& grid,int health,int x,int y,vector<vector<bool>>& visit){
        if(health<=0) return false;
        if(x==grid.size()-1 && y==grid[0].size()-1){
            return true;
        } 
        for(int i=0;i<4;i++){
            int nextx=x+dir[i][0];
            int nexty=y+dir[i][1];
            if(nextx<0 || nextx>=grid.size() || nexty<0 || nexty>=grid[0].size()) continue;
            if(visit[nextx][nexty]) continue;
            health-=grid[nextx][nexty];
            visit[nextx][nexty]=true;
            
            if(backtracking(grid,health,nextx,nexty,visit)){
                return true;
            }
            visit[nextx][nexty]=false;
            health+=grid[nextx][nexty];
        }
        return false;
    }
public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<bool>> visit(n,vector<bool>(m,false));
        health-=grid[0][0];
        visit[0][0]=true;
        if(health<=0) return false;
        if(backtracking(grid,health,0,0,visit)) return true;
        else return false;
    }
};