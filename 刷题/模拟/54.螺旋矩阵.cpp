//维护上下，左右边界
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();
        int up=0,down=m-1;
        int left=0,right=n-1;
        vector<int> result;
        while(up<=down && left<=right){
            for(int j=left;j<=right;j++){
                result.push_back(matrix[up][j]);
            }
            up++;
            if(up>down) break;

            for(int i=up;i<=down;i++){
                result.push_back(matrix[i][right]);
            }
            right--;
            if(left>right) break;

            for(int j=right;j>=left;j--){
                result.push_back(matrix[down][j]);
            }
            down--;
            if(up>down) break;

            for(int i=down;i>=up;i--){
                result.push_back(matrix[i][left]);
            }
            left++;
            if(left>right) break;
        }
        return result;
    }
};