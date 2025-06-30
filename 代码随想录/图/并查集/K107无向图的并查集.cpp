//使用并查集，只要两个的父节点是一样的，就在同一个集合中
#include <iostream>
#include <vector>

using namespace std;

void init(vector<int>& father,int n){
    for(int i=1;i<=n;i++){
        father[i]=i;
    }
}
int find(vector<int>& father,int x){
    if(father[x]==x){
        return x;
    }
    if(father[x]!=x){
        father[x]=find(father,father[x]);
    }
    return father[x];
}

void join(vector<int>& father,int x,int y){
    x=find(father,x);
    y=find(father,y);
    if(x==y){
        return ;
    }
    else{
        father[y]=x;
    }
}

int main(){
    int n,m;
    while(cin >> n >> m){
        vector<int> father(n+1);
        init(father,n);
        while(m--){
            int a,b;
            cin >> a >> b;
            join(father,a,b);
        }
        int sour,dest;
        cin >> sour >> dest;
        if(find(father,sour)== find(father,dest)) {
            cout << 1 <<endl;
        }
        else{
            cout << 0 <<endl;
        }
    }
    return 0;
}