class Solution {
public:
    static bool compare(vector<int> a, vector<int> b){
        return a[0]<b[0];
    }
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        //按照左边界从小到排列
        sort(intervals.begin(),intervals.end(),compare);
        int left=intervals[0][0],right=intervals[0][1];
        vector<vector<int>> res;
        for(int i=1;i<intervals.size();i++){
            if(intervals[i-1][1]>=intervals[i][0]){  //肯定重叠了
                right=max(intervals[i-1][1],intervals[i][1]);
                intervals[i][1]=right;
            }
            else{ //不重叠
                res.push_back({left,right});
                left=intervals[i][0];
                right=intervals[i][1];
            }
        }
        res.push_back({left,right});
        return res;
    }
};