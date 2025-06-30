class Solution {
private:
    vector<int> path;
    vector<int> used=vector<int>(100,0);
    vector<vector<int>> result;
    void backtracking(vector<int>& nums,int startindex){
        result.push_back(path);
        for(int i=startindex;i<nums.size();i++){
            if(i>0 && nums[i]==nums[i-1] && used[i-1]==0){
                continue;
            }
            path.push_back(nums[i]);
            used[i]=1;
            backtracking(nums,i+1);
            path.pop_back();
            used[i]=0;
        }
        return ;
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        path.clear();
        result.clear();
        sort(nums.begin(),nums.end());
        backtracking(nums,0);
        return result;
    }
};