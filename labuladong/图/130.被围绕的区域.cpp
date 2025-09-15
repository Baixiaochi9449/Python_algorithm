class Solution {
private:
    vector<vector<int>> visit;
    void dfs(vector<vector<char>>& board,int x,int y){
        int n=board.size();
        int m=board[0].size();
        if(x<0 || x>=n || y<0 || y>=m) return ;
        if(board[x][y]=='X') return ;
        if(visit[x][y]==-1) return ;
        if(board[x][y]=='O'){
            visit[x][y]=-1;
            dfs(board,x-1,y);
            dfs(board,x+1,y);
            dfs(board,x,y+1);
            dfs(board,x,y-1);
        }
        return ;
    }
public:
    void solve(vector<vector<char>>& board) {
        //首先遍历边缘的单元格，把边缘的单元格 和边缘单元格四周的是0的单元格全变为-1
        //开始遍历单元格，如果是0 且不是-1， 变为x
        int n=board.size();
        int m=board[0].size();
        
        visit=vector<vector<int>>(n,vector<int>(m,1));
        for(int i=0;i<n;i++){
            dfs(board,i,0);
            dfs(board,i,m-1);
        }
        for(int j=0;j<m;j++){
            dfs(board,0,j);
            dfs(board,n-1,j);
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]=='O' && visit[i][j]!=-1){
                    board[i][j]='X';
                }
            }
        }
    }
};
