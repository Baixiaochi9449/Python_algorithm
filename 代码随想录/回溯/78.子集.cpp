class Solution {
private:
    vector<int> path;
    vector<vector<int>> result;
    void backtracking(vector<int>& nums ,int startindex){
        result.push_back(path);
        for(int i=startindex;i<nums.size();i++){
            path.push_back(nums[i]);
            backtracking(nums,i+1);
            path.pop_back();
        }
        return ;
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        path.clear();
        result.clear();
        backtracking(nums,0);
        return result;
    }
};