
//先排序，然后找到前k个 mist=0的边，把权值加倍
//意思是尽可能让树里的 最小值 最大
//正序倒序都试试
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
    int maxStability(int n, vector<vector<int>>& edges, int k) {
        int m=edges.size();
        sort(edges.begin(),edges.end(),[](const auto& a,const auto& b){
            return a[2]>b[2];
        });
        int min_v=10000000;
        int count_edge=0;
        //思路是遍历2边树
        init();
        for(int i=0;i<m;i++){
            if(edges[i][3]==1){
                join(edges[i][0],edges[i][1]);
                count_edge++;
                min_v=min(min_v,edges[i][2]);
            }
        }
       
        for(int i=0;i<m;i++){
            if(edges[i][3]==0 && !isSame(edges[i][0],edges[i][1])){
                join(edges[i][0],edges[i][1]);
                count_edge++;
                if(k!=0){
                    min_v = min(min_v,edges[i][2]*2);
                    k--;
                }
                else{
                    min_v = min(min_v,edges[i][2]);
                }
            }
        }
        if(count_edge==n-1){
            return min_v;
        }
        else return -1;
        
    }
};