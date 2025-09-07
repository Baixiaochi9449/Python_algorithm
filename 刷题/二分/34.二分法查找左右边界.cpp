class Solution {
    public:
        vector<int> searchRange(vector<int>& nums, int target) {
            if(nums.size()==0) return {-1,-1};
            vector<int> res;
            int l=0,r=nums.size()-1;
            while(l<r){
                int mid=(l+r)/2;
                if(nums[mid]>=target) r=mid;
                else l=mid+1;   //寻找的左边界
            }
            if(nums[l]!=target) return {-1,-1};
    
            res.push_back(l);
    
            l=0,r=nums.size()-1;
            while(l<r){
                int mid=(l+r+1)/2;
                if(nums[mid]<=target) l=mid;
                else r=mid-1;
            }
            if(nums[r]!=target) return {-1,-1};
    
            res.push_back(r);
    
            return res;
        }
    };