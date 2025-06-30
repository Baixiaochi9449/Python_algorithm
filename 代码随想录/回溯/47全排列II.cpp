class Solution {
private:
    vector<int> path;
    vector<vector<int>> result;
    vector<int> used=vector<int>(100,0);
    void backtracking(vector<int>& nums){
        if(path.size()==nums.size()){
            result.push_back(path);
            return ;
        }
        set<int> uset;
        for(int i=0;i<nums.size();i++){
            if(used[i] || uset.find(nums[i])!=uset.end()){
                continue;
            }
            path.push_back(nums[i]);
            used[i]=1;
            uset.insert(nums[i]);
            backtracking(nums);
            path.pop_back();
            used[i]=0;
        }
    }
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        path.clear();
        result.clear();
        backtracking(nums);
        return result;
    }
};