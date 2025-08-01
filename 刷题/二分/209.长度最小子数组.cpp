//使用暴力做一遍
//二分法其实也是暴力，只不过是次数少的暴力，也是挨个试试，只不过是跳的距离大了
class Solution {
    public:
        int minSubArrayLen(int target, vector<int>& nums) {
            //首先保存前缀和，然后找l和r  [l,r] =s[r]-s[l-1]
            int n=nums.size();
            vector<int> s(n+1,0);
            s[0]=0;  //s[i] 前i个元素前缀和 。  s[0] 前0个元素前缀和
            for(int i=1;i<=n;i++){
                s[i]=s[i-1]+nums[i-1];
            }
    
       //可通过二分查找得到大于或等于 i 的最小下标 bound，使得 sums[bound]−sums[i−1]≥s，
            int min_count=INT_MAX;
            for(int i=1;i<=n;i++){
                int l=i,r=n;
                while(l<r){
                    int mid=(l+r)/2;
                    if(s[mid]-s[i-1]>=target) r=mid;
                    else l=mid+1;
                }
                if (s[l] - s[i - 1] >= target) {
                    min_count = min(min_count, l - i + 1);
               }
            }
            if(min_count==INT_MAX) return 0;
            else return min_count;
        }
    };