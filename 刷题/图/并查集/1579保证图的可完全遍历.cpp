//设置fatherA和fatherB,分别用并查集。  先把公共边加进来，然后分别遍历A和B所在的各自的边，判断是否删除
class Solution {
public:

    void init(vector<int>& father){
        int n=father.size();
        for(int i=0;i<n;i++){
            father[i]=i;
        }
    }
    int Find(vector<int>& father,int x){
        if(x==father[x]) return x;
        else{
            father[x]=Find(father,father[x]);
            return father[x];
        }
    }
    bool isSame(vector<int>& father,int x,int y){
        x=Find(father,x);
        y=Find(father,y);
        if(x==y) return true;
        else return false;
    }
    void join(vector<int>& father,int x,int y){
        x=Find(father,x);
        y=Find(father,y);
        if(x!=y){
            father[y]=x;
        }
    }

    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        vector<int> fA(n+1);
        vector<int> fB(n+1);
        int result=0;
        init(fA);
        init(fB);
        for(auto edge:edges){
            if(edge[0]==3){
                if(isSame(fA,edge[1],edge[2])){   //fA冗余了，那么fB肯定也冗余了
                    result++;
                    continue;
                }
                join(fA,edge[1],edge[2]);
                join(fB,edge[1],edge[2]);
            }
        }
        for(auto edge:edges){
            if(edge[0]==1){
                if(isSame(fA,edge[1],edge[2])){
                    result++;
                    continue;
                }
                join(fA,edge[1],edge[2]);
            }
            if(edge[0]==2){
                if(isSame(fB,edge[1],edge[2])){
                    result++;
                    continue;
                }
                join(fB,edge[1],edge[2]);
            }
        }
        for(int i=1;i<n;i++){
            if(!isSame(fA,i,i+1)) return -1;
            if(!isSame(fB,i,i+1)) return -1;
        }
        return result;
    }
};