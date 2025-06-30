//因为n个节点n条边,且在有向树的基础上，添加了一条边。所以最多有1个节点，有2个入度
//情况1：存在有2个入度的点，删掉2条边中的任意一条，不会有孤立的点
//情况1：存在有2个入度的点，删掉2条边中其中一条，会有孤立的点
//情况3：不存在有2个入度的点，存在环，所以删除任意一条边即可（最后一条边）
//思路：
//1.存储图的时候，把边和入度都存储起来。  ?什么存 edges.push_back({s,t}) indgree[t]++
//2. 再用一个vec存储2个入度的点 对应的2条边的索引。 ？如何找  indgree[edges[i].second]==2  存储边的索引i
//   最后的vec中，只有vec[0] vec[1]    edges[vec[0]] 

#include <iostream>
#include <vector>

using namespace std;
vector<int> father(100);

void init(vector<pair<int,int>>& graph){
    for(int i=1;i<=graph.size();i++){
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

bool isTreeafterdelete(vector<pair<int,int>>& graph,int del){
    init(graph);
    for(int i=0;i<graph.size();i++){
        if(i==del) continue;
        join(graph[i].first,graph[i].second);
    }
    for(int i=0;i<graph.size();i++){
        if(!isSame(graph[i].first,graph[i].second)){
            return false;
        }
    }
    return true;
}

int main(){
    int n;
    while(cin >> n){
        vector<pair<int,int>> graph;
        vector<int> indegree(n+1,0);
        for(int i=0;i<n;i++){   //这里会导致，后面的n的值都变成了0？
            int s,t;
            cin >> s >> t;
            graph.push_back({s,t});
            indegree[t]++;
        }
        vector<int> vec;
        for(int i=0;i<n;i++){
            if(indegree[graph[i].second]==2){   //存储了 1 3边的索引 和2 3边的索引
                vec.push_back(i);
            }
        }
        // cout << vec[0] << vec[1] <<endl;
        if(vec.size()>0){
            //判断删掉最后一个边后是否为联通图（按照无向图来做）
            if(isTreeafterdelete(graph,vec[1])){
                cout << graph[vec[1]].first << ' ' << graph[vec[1]].second << endl;
                
            }
            else{
                cout << graph[vec[0]].first << ' ' << graph[vec[0]].second << endl;
            }
        }
        else{
            //按并查集来做的冗余的边I
            init(graph);
            for(int i=0;i<graph.size();i++){
                if(isSame(graph[i].first,graph[i].second)){
                    cout << graph[i].first << ' ' << graph[i].second << endl; 
                }
                else{
                    join(graph[i].first,graph[i].second);
                }
            }
        }

    }
    return 0;
}