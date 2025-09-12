class Solution {
    private:
        vector<vector<int>> res;
        vector<int> path;  //外部的，需要回溯
        vector<bool> used;  //外部的，需要回溯，这里不能初始化，需要在参数里面传
        //最好都写上回溯
        void backtracking(vector<int>& nums,vector<bool>& used,int start){
            if(start==nums.size()){
                res.push_back(path);
                return ;
            }
            for(int i=0;i<nums.size();i++){
                if(used[i]) continue;
                used[i]=true;
                path.push_back(nums[i]);
                backtracking(nums,used,start+1);
                path.pop_back();
                used[i]=false;
            }
            return ;
        }
    public:
        vector<vector<int>> permute(vector<int>& nums) {
            //用一个used数组，在每次递归的时候传递，这个需要有回溯，外部传入的
            int n=nums.size();
            used=vector<bool>(n,false);
            backtracking(nums,used,0);
            return res;
        }
    };