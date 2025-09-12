//比我的暴力法更好一点的暴力：枚举左边界i, 枚举右边界j的时候，一边向右走，一边记录当前已经走过的最小的高，每次都算面积，记录一个最小的
class Solution {
    public:
        int largestRectangleArea(vector<int>& heights) {
            //先找左边第一个比i矮的，右边第一个比i矮的
            int n=heights.size();
            vector<int> left(n);
            vector<int> right(n);
            stack<int> sta;
            for(int i=0;i<n;i++){
                while(!sta.empty() && heights[sta.top()]>=heights[i]){
                    sta.pop();
                }
                if(sta.empty()) left[i]=-1;  //左边没有比i矮的
                else left[i]=sta.top();
                sta.push(i);
            }
    
            while(!sta.empty()) sta.pop();
            for(int i=n-1;i>=0;i--){
                while(!sta.empty() && heights[sta.top()]>=heights[i]){
                    sta.pop();
                }
                if(sta.empty()) right[i]=n;
                else right[i]=sta.top();
                sta.push(i);
            }
            int res=0;
            for(int i=0;i<n;i++){
                int cur=heights[i]*(right[i]-left[i]-1);
                res=max(res,cur);
            }
            return res;
        }
    };