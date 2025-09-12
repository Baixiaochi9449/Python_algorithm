//有重复元素的全排列
//和组合的层间去重一样，先排列，然后used

class Solution {
private:
    vector<vector<int>> res;
    vector<int> path;
    vector<bool> visit;
    void backtracking(vector<int>& nums){
        if(path.size()==nums.size()){
            res.push_back(path);
            return ;
        }
        set<int> used;
        for(int i=0;i<nums.size();i++){
            if(visit[i]) continue;
            if(used.find(nums[i])!=used.end()) continue;
            visit[i]=true;
            used.insert(nums[i]);
            path.push_back(nums[i]);
            backtracking(nums);
            path.pop_back();
            visit[i]=false;
        }
        return ;
    }
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        visit=vector<bool>(n,false);
        backtracking(nums);
        return res;
    }
};
