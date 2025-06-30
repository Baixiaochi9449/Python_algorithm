class Solution {
private:
    vector<vector<int>> result;
    vector<int> path;
    vector<bool> used = vector<bool>(100, false);
    void backtracking(vector<int>& candidates,int target,int sum,int startidx){
        if(sum==target){
            result.push_back(path);
            return ;
        }
        
        for(int i=startidx;i<candidates.size()&& sum + candidates[i] <= target;i++){   //这里要跳过相同的           
            if(i>0 && candidates[i]==candidates[i-1] && used[i-1]==false){  //used[i-1]==0是树层，used[i-1]==1 是树枝，树枝不用去重
                continue;
            }

            path.push_back(candidates[i]);
            sum+=candidates[i];
            used[i]=true;
            backtracking(candidates,target,sum,i+1);  //这里可以顺着取值
            sum-=candidates[i];
            path.pop_back();
            used[i]=false;
        }
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        result.clear();
        path.clear();
        sort(candidates.begin(),candidates.end()); //默认从小到大
        backtracking(candidates,target,0,0);
        return result;
    }
};