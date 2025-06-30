#include <iostream>
#include <vector>
using namespace std;

void init(vector<int>& father){
    for(int i=0;i<father.size();i++){
        father[i]=i;
    }
    return ;
}

int find(vector<int>&father,int x){
    if(x==father[x]) return x;
    else{
        father[x]=find(father,father[x]);
        return father[x];
    }
}

bool isSame(vector<int>& father,int x,int y){
    x=find(father,x);
    y=find(father,y);
    if(x==y) return true;
    else return false;
}

void join(vector<int>& father,int x,int y){
    x=find(father,x);
    y=find(father,y);
    if(x!=y){
        father[y]=x;
    }
}

int main(){
    int n;
    while(cin >> n){
        vector<int> father(n+1);
        init(father);
        while(n--){
            int s,t;
            cin >> s >> t;
            if(isSame(father,s,t)){
                cout << s << ' '<< t;
                return 0;
            }
            else{
                join(father,s,t);
            }
        }
    }
    return 0;
}