//包含重复元素，还是层间去重 第二层，选了位置1的2 就不能选位置2的2
class Solution {
private:
    vector<vector<int>> res;
    vector<int> path;
    void backtracking(vector<int>& nums,int start){
        res.push_back(path);
        set<int> used;
        for(int i=start;i<nums.size();i++){
            if(used.find(nums[i])!=used.end()) continue;
            used.insert(nums[i]);
            path.push_back(nums[i]);
            backtracking(nums,i+1);
            path.pop_back();
        }
        return ;
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        backtracking(nums,0);
        return res;
    }
};
