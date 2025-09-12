//[1,2,3,4] ��ѡ��k����
//������⣬i��start��ʼ
class Solution {
private:
    vector<vector<int>> res;
    vector<int> path;
    void backtracking(int n,int k,int start){
        if(path.size()==k){
            res.push_back(path);
        }
        for(int i=start;i<=n;i++){
            path.push_back(i);
            backtracking(n,k,i+1);
            path.pop_back();
        }
        return ;
    }
public:
    vector<vector<int>> combine(int n, int k) {
        backtracking(n,k,1);
        return res;
    }
};
