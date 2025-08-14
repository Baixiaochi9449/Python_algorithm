class Solution {
public:
    static bool compare(vector<int> a ,vector<int> b){
        if(a[1]==b[1]) return a[0]<b[0];
        else return a[1]<b[1]; 
    }
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        //按照右边界排序
        int res=0;
        sort(intervals.begin(),intervals.end(),compare);
        for(int i=0;i<intervals.size()-1;i++){
            if(intervals[i][1]>intervals[i+1][0]){
                res++;
                intervals[i+1][0]=intervals[i][0];
                intervals[i+1][1]=intervals[i][1];
            }
        }
        return res;
    }
};