#include <iostream>
#include <vector>
using namespace std;

int MAX=1000;
vector<int> father(MAX);
vector<int> height(MAX);
vector<int> visit(MAX);
vector<int> indegree(MAX);

void Initial(){
    for(int i=0;i<MAX;i++){
        father[i]=i;
        height[i]=i;
        indegree[i]=0;
        visit[i]=false;
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

bool isTree(){
    bool flag=true;
    int root=0;
    int component=0;
    for(int i=0;i<MAX;i++){
        if(!visit[i]){
            continue;
        }
        if(i==father[i]){
            component++;
        }
        if(indegree[i]==0){
            root++;
        }
        else if(indegree[i]>1){
            flag=false;
        }
    }

    if(component!=1 || root !=1){    //不满足 ==1 && ==1 的通通都是false
        flag=false;
    }
    //如果是空集，也是树
    if(component==0 && root==0){
        flag=true;
    }
    return flag;
}

int main()
{
    int x,y;
    int caseid=1;
    Initial();
    while(cin >> x >> y){

        if(x==-1 && y==-1){
            break;
        }
        else if(x==0 && y==0){
            if(isTree()){
                cout << "Case " << caseid << " is a tree."  << endl;
                caseid++;
            }
            else{
                cout << "Case " << caseid << " is not a tree."  << endl;
                caseid++;
            }
            Initial();
        }
        else{
            Unin(x,y);
            indegree[y]++;
            visit[x]=true;
            visit[y]=true;
        }

    }
    return 0;

}