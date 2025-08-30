class Solution {
public:
    static int countIncreasingSubsequences(const vector<int>& nums, int start, int end) {
        if (start > end) return 0;
        
        int count = 1; // 至少包含第一个数
        int last = nums[start]; // 当前递增序列的最后一个数
        
        for (int i = start + 1; i <= end; i++) {
            if (nums[i] > last) {
                count++;
                last = nums[i];
            }
        }
        return count;
    }
    vector<int> canSeePersonsCount(vector<int>& heights) {
        //只会暴力，首先找到i右边第一个比它高的j,然后找i+1 到j 的递增序列的个数
        stack<int> sta;  //存储下标
        int n=heights.size();
        vector<int> ans(n);  //存储下标
        vector<int> res(n,0);
        for(int i=n-1;i>=0;i--){
            while(!sta.empty() && heights[sta.top()] < heights[i]){
                sta.pop();
            }
            if(sta.empty()) ans[i]=n-1;  //右边没有比它高的，所以直接找 到最后的递增区间
            else ans[i]=sta.top();
            sta.push(i);
        }
        for(int i=0;i<n-1;i++){
            int temp=countIncreasingSubsequences(heights,i+1,ans[i]);
            res[i]=temp;
        }
        
        return res;
    }
};
