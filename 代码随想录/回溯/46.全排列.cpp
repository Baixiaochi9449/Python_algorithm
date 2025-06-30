class Solution {
private:
    vector<int> path;
    vector<vector<int>> result;
    vector<int> used=vector<int>(100,0);
    void backtracking(vector<int>& nums,int count){
        if(count==nums.size()){
            result.push_back(path);
            return ;
        }
        for(int i=0;i<nums.size();i++){
            if(used[i]){
                continue;
            }
            path.push_back(nums[i]);
            used[i]=1;
            count+=1;
            backtracking(nums,count);
            path.pop_back();
            used[i]=0;
            count-=1;
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        path.clear();
        result.clear();
        backtracking(nums,0);
        return result;
    }
};