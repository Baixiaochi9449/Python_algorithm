class Solution {
    public:
        int minSubArrayLen(int target, vector<int>& nums) {
            //不存在负数，可以用滑动窗口？ 小于tatget的时候r++, 大于等于target的时候判断，并l++
            int INF=1e9+10;
            int res=INF;
            int n=nums.size();
    
            int l=0,r=0;  //左闭右开
            int cursum=0;
            while(r<n){
                cursum+=nums[r];
                r++;
                while(cursum>=target){
                    if(cursum>=target){
                        res=min(res,r-l);
                    }
                    cursum-=nums[l];
                    l++;
                }
            }
            if(res==INF) return 0;
            else return res;
        }
    };