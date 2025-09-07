class Solution {
    public:
        bool searchMatrix(vector<vector<int>>& matrix, int target) {
            //如何二分法查找矩阵？  对每一行进行二分查找
            for(int i=0;i<matrix.size();i++){
                int l=0,r=matrix[0].size()-1;
                while(l<r){
                    int mid=(l+r+1)/2;
                    if(matrix[i][mid]<=target) l=mid;
                    else r=mid-1; 
                }
                if(matrix[i][l]==target) return true;
            }
            return false;
        }
    };