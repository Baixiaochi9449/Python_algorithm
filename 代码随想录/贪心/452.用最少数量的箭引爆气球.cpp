//按照左边界排序，如果 points[i][0]<points[i+1][1] 则res++;
class Solution {
public:
    static bool compare(vector<int> a ,vector<int> b){
        return a[0]<b[0];
    }
    int findMinArrowShots(vector<vector<int>>& points) {
        int res=1;
        sort(points.begin(),points.end(),compare);
        int curright=points[0][1];
        for(int i=0;i<points.size()-1;i++){
            if(points[i][1]<points[i+1][0]) res++;
            else {
                points[i+1][1]=min(points[i+1][1],points[i][1]); //第一次出现重叠的情况，肯定是可以一起的。但是第三个就不一定了。所以这里直接更新就可以，影响的是下一个
            }

        }
        return res;
    }
};