class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n=nums.size();
        vector<int> pre(n);
        pre[0]=nums[0];
        int res=-1;
        for(int i=1;i<n;i++){
            pre[i]=pre[i-1]+nums[i];
        }
        for(int i=0;i<n;i++){
            int left,right;
            if(i==0){
                left=0;
                right=pre[n-1]-pre[0];
            }
            else if(i==n-1){
                left=pre[n-2];
                right=0;
            }
            else{
                left=pre[i-1];
                right=pre[n-1]-pre[i];
            }
            if(left==right) {
                res=i;
                break;
            }
        }
        return res;
    }
};
