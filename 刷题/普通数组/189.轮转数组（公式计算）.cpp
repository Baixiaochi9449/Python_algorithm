class Solution {
    public:
        void rotate(vector<int>& nums, int k) {
            //用队列不需要动脑子，最后再存回数组
            //法二：可以通过 i k 和n 计算出位置的。  移动 k%n个位置。  移动到 (i+k)%n 的位置
            int n=nums.size();
            vector<int> temp(n);
            for(int i=0;i<n;i++){
                int po=(i+k)%n;
                temp[po]=nums[i];
            }
            for(int i=0;i<n;i++){
                nums[i]=temp[i];
            }
        }
    };