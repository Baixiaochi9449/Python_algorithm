class Solution {
private:
    bool backtracking(vector<vector<char>>& board){
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board.size();j++){
                if (board[i][j] == '.') {  //只有遇到空格的时候才填数
                    for(char k='1';k<='9';k++){
                        if(isvalid(board,i,j,k)){
                            board[i][j]=k;
                            if(backtracking(board)){
                                return true;
                            }
                            board[i][j]='.';
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }
    bool isvalid(vector<vector<char>>& board,int row,int col,char k){
        //当前行有没有k
        for(int j=0;j<board.size();j++){
            if(board[row][j]==k){
                return false;
            }
        }
        //当前列有没有k
        for(int i=0;i<board.size();i++){
            if(board[i][col]==k){
                return false;
            }
        }
        int startRow = (row / 3) * 3;
        int startCol = (col / 3) * 3;
        for(int i=startRow;i<startRow+3;i++){
            for(int j=startCol;j<startCol+3;j++){
                if(board[i][j]==k){
                    return false;
                }
            }
        }
        return true;
    }
public:
    void solveSudoku(vector<vector<char>>& board) {
        backtracking(board);
    }
};