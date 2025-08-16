//区间覆盖，用最小的区间覆盖从0 到time的长度
//首先按照左边界从小到大排序，然后选能覆盖start的区间的最大的右边界。 然后判断。 然后start=最大右边界  i=j-1. 每次重新找最大右边界的时候，都要重新更新max_r=-1e9;
class Solution {
    public:
        static bool compare(vector<int>& a,vector<int>& b){
            return a[0]<b[0];
        }
        int videoStitching(vector<vector<int>>& clips, int time) {
            sort(clips.begin(),clips.end(),compare);
            int n=clips.size();
            int start=0;
            int res=0;
            for(int i=0;i<n;i++){
                int j=i,max_r=-1e9;
                while(j<n && clips[j][0]<=start){ //右满足的 左边界
                    max_r=max(max_r,clips[j][1]);
                    j++;
                }
                res++;
                if(max_r<start){
                    return -1;
                }
                if(max_r>=time) return res;
                start=max_r;
                i=j-1;
            }
            return -1;
        }
    };