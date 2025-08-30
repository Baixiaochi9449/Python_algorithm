class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        //环形数组： idx%n 对n取余就是环形。  所以就是直接把数组延长一倍。 
        int n=nums.size();
        vector<int> ans(n);
        stack<int> sta;
        for(int i=2*n-1;i>=0;i--){
            while(!sta.empty() && sta.top()<=nums[i%n]){
                sta.pop();
            }
            if(sta.empty()) ans[i%n]=-1;
            else ans[i%n]=sta.top();
            sta.push(nums[i%n]);
        }
        return ans;
    }
};
