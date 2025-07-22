//使用二分法，一边找target，一边找pre>cur的cur下标t，则这个下标原本应该为，所以target的下标为 ,当前下标-t或 (n-t)+当前下标 
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int left=0;
        int right=n-1;
        while(left<=right){
            int mid=(left+right)/2;
            if(nums[mid]==target) return mid;
            if(nums[0]<=nums[mid]){ //左侧为升序排列
                if(nums[0]<=target && target<nums[mid]){
                    right=mid-1;
                }else{
                    left = mid+1;
                }
            }
            else{  //左侧不是升序排列,则右侧肯定为升序排列
                if(nums[mid]<target && target<=nums[n-1]){
                    left = mid+1;
                }else{  //target在未升升序排列的左侧
                    right = mid-1;
                }
            }
        }
        return -1;
    }
};