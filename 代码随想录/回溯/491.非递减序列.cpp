class Solution {
private:
    vector<int> path;
    vector<vector<int>> result;
    void backtracking(vector<int>& nums,int startindex){
        if(path.size()>=2){
            result.push_back(path);
        }
        set<int> uset;
        for(int i=startindex;i<nums.size();i++){
            if((path.size() && nums[i]<path.back()) || uset.find(nums[i])!=uset.end()){
                continue;
            }
            path.push_back(nums[i]);
            uset.insert(nums[i]);
            backtracking(nums,i+1);
            path.pop_back();
        }
        return ;
    }
public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        path.clear();
        result.clear();
        backtracking(nums,0);
        return result;
    }
};