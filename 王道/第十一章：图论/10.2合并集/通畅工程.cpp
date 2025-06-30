//把有道路联通的城镇划分到同一个集合中。如果最后 除了根节点外，还有一个根节点，则这个就是集合外的
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
    if(father[x]!=x){
        father[x]=Find(father[x]);    //路径压缩
    }
    return father[x];
}

void Unin(int x,int y){
    x=Find(x);
    y=Find(y);
    if(x!=y){ 
        if(height[x]<height[y]){   //矮树作为高树的子树
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
    int N,M;
    while(cin >> N){
        if(N==0){
            break;
        }
        cin >> M;
        Initial(N);

        for(int i=0;i<M;i++){
            int x, y;
            cin >> x >> y;
            Unin(x,y);
        }
        int answer=-1;
        for(int i=1;i<=N;i++){
            if(i==father[i]){
                answer++;
            }
        }
        cout << answer<< endl;
    }
    return 0;
}