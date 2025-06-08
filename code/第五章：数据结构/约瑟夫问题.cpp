#include <iostream>
#include <queue>
using namespace std;

int main(){
    int n,p,m;
    while(cin>>n>>p>>m){
        if (n==0) break;
        else{
            queue<int> childern;
            for (int i=0;i<n;i++){
                childern.push(i+1);
            }
            for (int i=0;i<p-1;i++){
                childern.push(childern.front());
                childern.pop();
            }
            while(childern.size()>1){
                for (int i=0;i<m-1;i++){
                    childern.push(childern.front());
                    childern.pop();
                }
                cout << childern.front() << " ";
                childern.pop();
            }
            if (childern.size()==1){
                cout << childern.front() << endl;
            }
        }
    }
    return 0;
}