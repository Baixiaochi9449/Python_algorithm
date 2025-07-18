//val是横坐标差值 和 纵坐标差值 之和
//遍历所有点，把每2点之间的距离做统计记录下来，存储到 {i,val} 这样的二元组中，i是点的编号
class Solution {
public:
    struct Edge{
        int u,v,val;
    };
    static bool compare(const Edge& a,const Edge& b){
        if(a.val<b.val){
            return true;
        }
        else{
            return false;
        }
    }
    int father[1000]={0};
    void init(int n){
        for(int i=0;i<n;i++){
            father[i]=i;
        }
    }
    int Find(int x){
        if(father[x]==x){
            return x;
        }
        else{
            father[x]=Find(father[x]);
            return father[x];
        }
    }
    bool isSame(int x,int y){
        x=Find(x);
        y=Find(y);
        if(x==y) return true;
        else return false;
    }
    void join(int x,int y){
        x=Find(x);
        y=Find(y);
        if(x!=y){
            father[y]=x;
        }
    }
    int minCostConnectPoints(vector<vector<int>>& points) {
        vector<Edge> graph;
        for(int i=0;i<points.size();i++){
            for(int j=i+1;j<points.size();j++){
                int val = abs(points[i][0]-points[j][0])+abs(points[i][1]-points[j][1]);
                    graph.push_back({i,j,val});
            }
        }
        sort(graph.begin(),graph.end(),compare);
        init(points.size());
        int result=0;
        for(Edge edge:graph){
            if(isSame(edge.u,edge.v)){
                continue;
            }
            else{
                join(edge.u,edge.v);
                result+=edge.val;
            }
        }
        return result;
    }
};