class Solution {
    public:
        vector<int> maxSlidingWindow(vector<int>& nums, int k) {
            //用一个优先级队列，先把前k个数据填进去，top就是初始窗口最大值。 接着往后遍历，看top是否在窗口中，不在就弹出，直到找到top在窗口中，那就是最大的
            priority_queue<pair<int,int>> que;  //第二个int是存下标，为了方便找是否在窗口中
            vector<int> res;
            for(int i=0;i<k;i++){
                que.push({nums[i],i});
            }
            res.push_back(que.top().first);
            for(int i=k;i<nums.size();i++){
                que.push({nums[i],i});
                while(que.top().second<i-k+1){
                    que.pop();
                }
                res.push_back(que.top().first);
            }
            return res;
        }
    };