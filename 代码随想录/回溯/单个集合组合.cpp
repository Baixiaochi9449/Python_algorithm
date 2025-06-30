class Solution {
private:
    vector<int> path;
    vector<vector<int>> result;
    void backingtracking(int targetsum,int k,int sum,int startidx){
        if(sum>targetsum){
            return ;
        }
        if(path.size()==k){
            if(sum==targetsum){
                result.push_back(path);
            }
            return ;
        }
        for(int i=startidx;i<=9-(k-path.size())+1;i++){
            sum+=i;
            path.push_back(i);
            backingtracking(targetsum,k,sum,i+1);
            sum-=i;
            path.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        backingtracking(n,k,0,1);
        return result;
    }
};