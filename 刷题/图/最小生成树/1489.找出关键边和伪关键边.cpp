//如何找到所有的最小生成树
//不需要把图存储到什么邻接表或邻接矩阵直接用edges就可以
//这道题的关键是，多次运行MST，每个边一个一个枚举
class Solution {
public:
    static const int MAX=1000;
    int father[MAX];
    void init(){
        for(int i=0;i<MAX;i++){
            father[i]=i;
        }
    }
    int Find(int x){
        if(x==father[x]) return x;
        else{
            father[x]=Find(father[x]);
            return father[x];
        }
    }
    bool isSame(int x ,int y){
        x=Find(x);
        y = Find(y);
        if(x==y) return true;
        else return false;
    }
    void join(int x ,int y){
        x=Find(x);
        y=Find(y);
        if(x!=y){
            father[y]=x;
        }
    }
    
    vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>>& edges) {
        //首先计算出value,这里的一个处理是给每条边添加了编号。这样存储的时候就找编号就可以了
        int m = edges.size();
        for(int i=0;i<m;i++){
            edges[i].push_back(i);
        }
        sort(edges.begin(),edges.end(),[](const auto& u,const auto& v){
            return u[2]<v[2];
        });
        init();
        int value = 0;
        for(int i=0;i<m;i++){
            if(!isSame(edges[i][0],edges[i][1])){
                value+=edges[i][2];
                join(edges[i][0],edges[i][1]);
            }
        }

        //已知了value，接下来枚举每一条边，计算每一条边的v。把关键边和伪关键边的编号存储
        vector<vector<int>> ans(2);
        
        for(int i=0;i<m;i++){  //枚举每一条边，处理是 把枚举的边从图中删除
            //判断是否为关键边： ??如何判断是否存在最小生成树呢？
            init();
            int v=0;
            int edge_cont=0;  //生成树的边数，最后应该=n-1  节点数-1
            for(int j=0;j<m;j++){
                if(i!=j && !isSame(edges[j][0],edges[j][1])) {
                    v+=edges[j][2];
                    join(edges[j][0],edges[j][1]);
                    edge_cont++;
                }
            }
            if(edge_cont!=n-1 || v>value) {
                ans[0].push_back(edges[i][3]);
                continue;  //当前边已经是关键边了，直接不判断下面的了，直接下一条边
            }

            //判断是否为伪关键边
            init();
            join(edges[i][0],edges[i][1]);   //把当前边加进来，然后在不遍历当前边的时候用MST
            v=edges[i][2];
            for(int j=0;j<m;j++){
                if(i!=j && !isSame(edges[j][0],edges[j][1])){
                    v+=edges[j][2];
                    join(edges[j][0],edges[j][1]);
                }
            }
            if(v==value){
                ans[1].push_back(edges[i][3]);
            }
        }
        return ans;
    }
};