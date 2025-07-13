//求先求出每个子集
//终止条件，遍历到最后。 收集结果：每个节点。 
class Solution {
private:
    vector<vector<int>> result;
    vector<int> path;
    void backtracking(vector<int>& nums,int starindex){
        result.push_back(path);
        for(int i=starindex;i<nums.size();i++){
            path.push_back(nums[i]);
            backtracking(nums,i+1);
            path.pop_back();
        }
        return ;
    }
public:
    int subsetXORSum(vector<int>& nums) {
        result.clear();
        path.clear();
        backtracking(nums,0);
        int sum=0;
        for(int i=0;i<result.size();i++){
            vector<int> cur=result[i];
            if(cur.size()==0) continue;
            int cursum=cur[0];
            for(int j=1;j<cur.size();j++){
                cursum^=cur[j];
            }
            sum+=cursum;
        }
        return sum;
    }
};