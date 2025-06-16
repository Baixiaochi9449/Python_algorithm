#include <cstdio>
#include <iostream>
#include <string>
#include <cstring>
using namespace std;


int direction[8][2]={{1,2},{1,-2},{-1,2},{-1,-2},{2,1},{2,-1},{-2,-1},{-2,1}};
bool visit[30][30];

int p,q;

bool DFS(int x,int y,int step,string str){
    if(step==p*q){
        cout << str << endl;
        return true;   //true和false代表能不能走到最后
    }
    else{
        for(int i=0;i<8;i++){
            int nx=x+direction[i][0];
            int ny=y+direction[i][1];
            char col=ny+'A';
            char row=nx+'1';
            if(nx>=p || nx<0 || ny<0 || ny>=q || visit[nx][ny]){
                continue;
            }
            visit[nx][ny]=true;
            if(DFS(nx,ny,step+1,str+col+row)){
                return true;    //不是每一步都会true,而是一层一层的执行DFS，只有到直行道最后，才会返回true,说明能一直走下去。如果中途DFS不能执行了，会在最后一个DFS，执行下面的visit=false,也就是回溯。 然后再次希望一直能执行下去，希望能返回true。如果一直回溯都没有，那就返回false。  这个return无论递归多少次，都只有最后才会执行最后的结果。
            }
            visit[nx][ny]=false;  //如果没有 走到这里，就变成false,说明要回溯了
        }
    }
    return false;
}


int main(){
    int n;
    cin >> n;
    while(n--){
        cin >> p >> q;
        memset(visit,false,sizeof(visit));
        visit[0][0]=true;
        if(!DFS(0,0,1,"A1")){
            cout << "impossible" <<endl;
        }
    }
    return 0;
}