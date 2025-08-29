class Solution {
public:
    static bool compare(vector<int>& a,vector<int>& b){
        return a[1]>b[1];
    }
    vector<int> topKFrequent(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        vector<int> res;
        for(int i=0;i<nums.size();i++){
            int cout=0,j=i;
            while(j+1<nums.size() && nums[j]==nums[j+1]){
                cout++;
                j++;
            }
            ans.push_back({nums[i],cout});
            i=j;
        }
        sort(ans.begin(),ans.end(),compare);
        for(int i=0;i<k;i++){
            res.push_back(ans[i][0]);
        }
        return res;
    }
};
