//不是每次更新fast最远距离的时候就跳，而是，当前已经到达 起始位置能跳的最大距离的时候end,就jump++
class Solution {
    public:
        int jump(vector<int>& nums) {
            int fastlength=0;
            int end=0;
            int jump=0;
            for(int i=0;i<nums.size()-1;i++){
              fastlength=max(fastlength,i+nums[i]);
              if(i==end){
                jump++;
                end=fastlength;
                if(fastlength>=nums.size()-1) break;
              }
            }
            return jump;
        }
    };