//不是并查集的原因，因为多使用了一个queue所以， 内存占用太多了

///第一个是不使用queue
///第二个是使用了queue
//都能实现BFS，只不过不适用queue有种滚动的感觉，反正queue都是放一个，拿出去一个，那就直接放到一个变量里，一直变这个变量，因为queue还要开拓一片空间。












class Solution {
    static constexpr int dir[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
   
// private:
//     int father[1000];
//     void init(int n){
//         for(int i=0;i<n;i++){
//             father[i]=i;
//         }
//     }
//     int Find(int x){
//         if(father[x]==x) return x;
//         else{
//             father[x]=Find(father[x]);
//             return father[x];
//         }
//     }
//     bool isSame(int x,int y){
//         x=Find(x);
//         y=Find(y);
//         if(y==x) return true;
//         else return false;
//     }
//     void join(int x,int y){
//         x=Find(x);
//         y=Find(y);
//         if(x!=y){
//             father[y]=x;
//         }
//     }
public:
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        //首先把所有的1的位置存储到vector<pair<int,int>> one_position里面
        //从每个1出发，广度优先搜索，把走1步能到的存储，走2步能到的存储
        //dis[i][j] 代表，i, j这个位置距离1的距离
        //vector<vector<pair<int,int>>> groups.  groups[0]里面存储了one_position
        int n = grid.size();
        vector<vector<int>> dis(n,vector<int>(n,-1));  //初始化全都是-1
        vector<pair<int,int>> one_position;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    dis[i][j]=0;
                    one_position.push_back({i,j});
                }
            }
        }
        vector<vector<pair<int,int>>> groups;
        groups.push_back(one_position);
        queue<vector<pair<int,int>>> que;
        que.push(one_position);
        while(!que.empty()){
            vector<pair<int,int>> cur = que.front();
            que.pop();
            vector<pair<int,int>> temp;
            for(auto &[i,j] :cur ){ //第一次的话，就是遍历 距离1为0的点 ，因为他们的下一个就是距离1为1的点 
                for(int k=0;k<4;k++){  //四个方向找下一个值
                    int nextx=i+dir[k][0];
                    int nexty=j+dir[k][1];
                    if(nextx<0 || nexty<0 || nextx>=n || nexty>=n) continue;
                    if(dis[nextx][nexty]!=-1) continue; //大于0说明这个位置已经被赋值了,就跳过
                    dis[nextx][nexty]=groups.size();
                    temp.push_back({nextx,nexty});
                }

            }
            que.push(temp);
            groups.push_back(temp);
        }
        //groups里面存储了, groups[0] 距离1为0的点的坐标....
        //dis[i][j]每个点i,j距离 1的距离
        //开始从大到小枚举，同时判断是否可以从左上到右下。最大的一个数是 groups.size()-2???
        vector<int> fa(n*n);
        iota(fa.begin(),fa.end(),0);
        function<int(int)> find = [&](int x) -> int { return fa[x] == x ? x : fa[x] = find(fa[x]); };
        
        for(int ans = groups.size()-2;ans>0;ans--){  //从最大的答案开始
            for(auto &[i,j] : groups[ans]){  //这是距离1 为（如2）的所有点，把能走的下一个位置，把他们都连接起来。
                for(int k=0;k<4;k++){
                    int nextx = i +dir[k][0];
                    int nexty = j +dir[k][1];
                    if(nextx<0 || nexty<0 || nextx>=n || nexty>=n) continue;
                    if(dis[nextx][nexty]<ans) continue; //只能走大于等于ans的位置
                    fa[find(nextx*n+nexty)]=find(i*n+j); //坐标转化为整数
                }
            }
            if(find(0)==find(n*n-1)) return ans;
        }
        return 0;
    }
};

