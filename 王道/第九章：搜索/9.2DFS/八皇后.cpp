#include <iostream>
#include <vector>
using namespace std;

vector<int> All_ways;
vector<vector<int>> Q(8, vector<int>(8, 0));

bool judge(int row,int col){
    //不用判断当前行，因为是从上往下遍历的，只需要判断左上角和右上角
    //当前col上不能有1
    for(int i=0;i<8;i++){
        if(Q[i][col]==1){
            return false;
        }
    }
    for(int i=row,j=col;i>=0&& j>=0;--i,--j){
        if(Q[i][j]==1){
            return false;
        }
    }
    for(int i=row,j=col;i>=0 && j<8;i--,j++){
        if(Q[i][j]==1){
            return false;
        }
    }
    return true;
}


void DFS(int row,int ans){
    if(row==8){
        All_ways.push_back(ans);
        return ;
    }
    else{
        for(int col=0;col<8;col++){
            if(judge(row,col)){
                Q[row][col]=1;
                int next=ans*10+col+1;
                DFS(row+1,next);
                Q[row][col]=0;   //回退
            }
        }
    }
}

int main(){
    int n;
    while(cin >> n){
        DFS(0,0);
        cout << All_ways[n-1] << endl;
    }
    return 0;
}