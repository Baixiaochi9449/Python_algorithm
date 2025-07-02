//读入的时候，一边读，一边join
//再重新遍历，判断isSame 如果false 就count++,然后join
#include <iostream>
#include <vector>
using namespace std;

vector<int> father(1000);

void init(){
    for(int i=1;i<=1000;i++){
        father[i]=i;
    }
}

int find(int x){
    if(father[x]==x){
        return x;
    }
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

bool isSame(int x,int y){
    x=find(x);
    y=find(y);
    if(x==y){
        return true;
    }
    else{
        return false;
    }
}


int main(){
    int n,m;
    while(cin >> n >> m){
        init();
        while(m--){
            int s,t;
            cin >> s >> t;
            join(s,t);
        }
        int sum=0;
        for(int i=1;i<n;i++){
            if(!isSame(i,i+1)){
                sum++;
                join(i,i+1);
            }
        }
        cout << sum << endl;
    }
    return 0;
}