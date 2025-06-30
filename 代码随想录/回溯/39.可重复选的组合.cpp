class Solution {
private:
    vector<vector<int>> result;
    vector<int> path;
    void backtracking(vector<int> candidates,int target,int startidx,int sum){
        if(sum>target){
            return ;
        }
        if(sum==target){
            result.push_back(path);
            return ;
        }
        for(int i=startidx;i<candidates.size();i++){
            sum+=candidates[i];
            path.push_back(candidates[i]);
            backtracking(candidates,target,i,sum);
            sum-=candidates[i];
            path.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        backtracking(candidates,target,0,0);
        return result;
    }
};