#include <iostream>
#include <vector>
using namespace std;

//全排列，需要维护一个used[i] ,在递归的时候维护，参与回溯过程
int n;
vector<int> path;
vector<int> used(1000000,0);
void backtracking(){
    if(path.size()==n){
        for(int i=0;i<n;i++){
            cout << path[i] <<' ';
        }
        cout << endl;
    }
    for(int i=1;i<=n;i++){
        if(used[i]==1){
            continue;
        }
        else{
            path.push_back(i);
            used[i]=1;
            backtracking();
            path.pop_back();
            used[i]=0;
        }
    }
    return ;
}

int main(){
    cin >> n;
    backtracking();
    return 0;
    
}
