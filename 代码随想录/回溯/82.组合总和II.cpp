//树层去重，树枝不去重 ----每层递归有新的set
//递归参数：candidates,target,sum ,starindex
//终止条件： target==sum
//单层搜索逻辑：
class Solution {
private:
    vector<vector<int>> result;
    vector<int> path;
    void backtracking(vector<int>& candidates,int target,int sum,int starindex){
        if(sum==target){
            result.push_back(path);
            return ;
        }
        unordered_set<int> numset;
        for(int i=starindex;i<candidates.size();i++){
            if(numset.count(candidates[i])) continue;
            if(candidates[i]+sum>target) continue;
            
            path.push_back(candidates[i]);
            numset.insert(candidates[i]);
            backtracking(candidates,target,candidates[i]+sum,i+1);
            path.pop_back();
        }
        return ;
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        result.clear();
        path.clear();
        sort(candidates.begin(),candidates.end());
        backtracking(candidates,target,0,0);
        return result;
    }
};