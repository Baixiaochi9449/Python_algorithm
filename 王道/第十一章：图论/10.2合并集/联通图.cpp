#include <iostream>
#include <vector>

using namespace std;

int MAX=1000;
vector<int> father(MAX);
vector<int> height(MAX);

void Initial(int n){
    for(int i=1;i<=n;i++){
        father[i]=i;
        height[i]=0;
    }
}

int Find(int x){
    if(x!=father[x]){
        father[x]=Find(father[x]);
    }
    return father[x];
}

void Unin(int x,int y){
    x=Find(x);
    y=Find(y);
    if(x!=y){
        if(height[x]<height[y]){
            father[x]=y;
        }
        else if(height[x]>height[y]){
            father[y]=x;
        }
        else{
            father[y]=x;
            height[x]++;
        }
    }
    return ;
}

int main(){
    int n,m;
    while(cin >> n>>m){
        if(n==0){
            break;
        }
        Initial(n);
        for(int i=0;i<m;i++){
            int x,y;
            cin >> x >>y;
            Unin(x,y);
        }
        bool isyes=true;
        int answer=0;
        for(int i=1;i<=n;i++){
            if(i==father[i]){
               answer++;
            }
        }
        if(answer==1){
            cout<< "YES" << endl;
        }
        else{
            cout << "NO" <<endl;
        }
    }
    return 0;
}