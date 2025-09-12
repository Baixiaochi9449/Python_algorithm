//1-9  十个数选K个，使它们的和为n
//收集条件 ，cont==k if(==) 
//树层： 简单的
class Solution {
private:
    vector<vector<int>> res;
    vector<int> path;
    void backtracking(int k,int n,int start,int sum){
        if(path.size()==k && sum==n){
            res.push_back(path);
            return ;
        }
        for(int i=start;i<=9;i++){
            if(i>n) return ;
            path.push_back(i);
            sum+=i;
            backtracking(k,n,i+1,sum);
            sum-=i;
            path.pop_back(); 
        }
        return ;
    }
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        backtracking(k,n,1,0);
        return res;
    }
};
