class Solution {
    public:
        vector<vector<int>> threeSum(vector<int>& nums) {
            //先确定i 然后再双指针j和k 。双指针移动有个依据？根据什么来移动呢？ 直觉？ 与下标无关！所以可以先排序！
            //还需要一个memo
            set<vector<int>> memo;
            sort(nums.begin(),nums.end());
            vector<vector<int>> res;
            for(int i=0;i<nums.size()-1;i++){
                int j=i+1,k=nums.size()-1;
                while(j!=k){
                    if(nums[i]+nums[j]+nums[k]==0){
                        vector<int> temp={nums[i],nums[j],nums[k]};
                        if(!memo.count(temp)){
                            memo.insert(temp);
                            res.push_back(temp);
                        }
                        j++;
                    }
                    else if(nums[i]+nums[j]+nums[k]<0){
                        j++;
                    }
                    else{
                        k--;
                    }
                }
            }
            return res;
        }
    };