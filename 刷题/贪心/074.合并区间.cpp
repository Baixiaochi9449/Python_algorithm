class Solution {
public:
    static bool compare(vector<int>& a,vector<int>& b){
        return a[0]<b[0];
    }
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        //在重叠的里面找max_r,先按照左边界排序
        vector<vector<int>> ans;
        sort(intervals.begin(),intervals.end(),compare);
        int n=intervals.size();
        for(int i=0;i<n;i++){
            int j=i+1;
            int begin=intervals[i][0],max_r=intervals[i][1];
            while(j<n && max_r>=intervals[j][0]){ //重叠
                max_r=max(max_r,intervals[j][1]);
                j++;
            }
            ans.push_back({begin,max_r});
            i=j-1;
        }
        return ans;
    }
};
