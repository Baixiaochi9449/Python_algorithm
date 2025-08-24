#include <iostream>
#include <vector>
using namespace std;

int MAX=1e5+1;
vector<int> father(MAX,0);
void init(){
    for(int i=0;i<MAX;i++){
        father[i]=i;
    }
}
int find(int x){
    if(x==father[x]) return x;
    else{
        father[x]=find(father[x]);
        return father[x];
    }
}
void join(int x,int y){
    x=find(x);
    y=find(y);
    if(x!=y){
        father[y]=x;
    }
}
bool isSame(int x ,int y){
    x=find(x);
    y=find(y);
    return x==y;
}
int main(){
    int n,m;
    cin >> n >> m;
    init();
    while(m--){
        char op;
        int a,b;
        cin >> op >> a >> b;
        if(op=='M'){
            join(a,b);
        }
        else{
            if(isSame(a,b)) cout << "Yes" << endl;
            else cout << "No" << endl;
        }
    }
    return 0;
}