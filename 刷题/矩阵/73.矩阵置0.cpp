class Solution {
    public:
        void setZeroes(vector<vector<int>>& matrix) {
            //遍历一遍，先记录所在的行和列，然后再遍历行和列，对矩阵改变
            set<pair<int,int>> memo; 
            int n=matrix.size();
            int m=matrix[0].size();
            for(int i=0;i<n;i++){
                for(int j=0;j<m;j++){
                    if(matrix[i][j]==0){
                        if(!memo.count({i,j})) memo.insert({i,j});
                    }
                }
            }
            for(auto it=memo.begin();it!=memo.end();it++){
                int i=it->first;
                int j=it->second;
                for(int k=0;k<m;k++){
                    matrix[i][k]=0;
                }
                for(int k=0;k<n;k++){
                    matrix[k][j]=0;
                }
            }
        }
    };