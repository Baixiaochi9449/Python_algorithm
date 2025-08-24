//用一个memo记录同一个father的数量
//如果1和2已经连起来了 1--1 2--1   如果3和5 已经连起来了  3--3  5--3   如何把2 和5 连起来？  
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
    vector<int> result(n+1,1);
    while(m--){
        string op;
        int a,b;
        cin >> op >> a ;
        if(op=="C"){
            cin >> b;
            if(isSame(a,b)) continue;
            else{
                result[find(a)]+=result[find(b)];
                join(a,b);
            }
        }
        else if(op=="Q1"){
            cin >> b;
            if(isSame(a,b)){
                cout << "Yes"  << endl;
            }
            else cout << "No" << endl;
        }
        else {
            cout << result[find(a)] << endl; 
        }
    }
    return 0;
}
