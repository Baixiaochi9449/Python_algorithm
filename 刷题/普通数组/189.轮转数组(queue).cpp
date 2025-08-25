class Solution {
    public:
        void rotate(vector<int>& nums, int k) {
            //用队列不需要动脑子，最后再存回数组
            queue<int> que;
            int n=nums.size();
            for(int i=n-1;i>=0;i--){
                que.push(nums[i]);
            }
            while(k--){
                int temp=que.front();
                que.pop();
                que.push(temp);
            }
            for(int i=n-1;i>=0;i--){
                nums[i]=que.front();
                que.pop();
            }
        }
    };