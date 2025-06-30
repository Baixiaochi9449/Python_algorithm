//next 上下左右四个方向
//先遍历，找到对应的字母---再找next
//终止条件，当前字符==word
//参数：board,word,cur
//先找到开头的字母，然后递归。找到开头的字母在main里
class Solution {
private:
    vector<vector<bool>> visit = vector<vector<bool>>(100, vector<bool>(100, false));
    vector<vector<int>> dir={{0,-1},{0,1},{1,0},{-1,0}};
    bool backtracking(vector<vector<char>>& board, string word,int starindex,int x,int y){
        if(starindex==word.size()) return true;
        
    
        for(int i=0;i<4;i++){
            int nextx=x+dir[i][0];
            int nexty=y+dir[i][1];
            if(nextx<0 || nextx>=board.size() || nexty<0 || nexty>=board[0].size()) continue;
            if(visit[nextx][nexty]) continue;
            if(board[nextx][nexty]!=word[starindex]) continue;
            visit[nextx][nexty]=true;
            if(backtracking(board,word,starindex+1,nextx,nexty)){
                return true;
            }
            visit[nextx][nexty]=false;
        }
        return false;
        
    }
public:
    bool exist(vector<vector<char>>& board, string word) {

        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                if(board[i][j]==word[0]){
                    visit[i][j]=true;
                    if(backtracking(board,word,1,i,j)) return true;
                }
                visit[i][j]=false;
            }
        }

        return false;
    }
};