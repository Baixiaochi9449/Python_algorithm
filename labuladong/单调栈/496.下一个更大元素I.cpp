class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        //感觉nums1像在查询。 所以先求出nums2的ans数组
        stack<int> sta;
        int n=nums2.size();
        vector<int> ans(n);
        int m=nums1.size();
        vector<int> res;
        for(int i=n-1;i>=0;i--){
            while(!sta.empty() && sta.top()<=nums2[i]) { //移除栈中比 当前数 小的元素
                sta.pop();
            }
            if(sta.empty()) ans[i]=-1;
            else ans[i]=sta.top();
            sta.push(nums2[i]);
        }
        for(int j=0;j<m;j++){
            for(int i=0;i<n;i++){
                if(nums2[i]==nums1[j]){
                    res.push_back(ans[i]);
                }
            }
        }
        return res;
    }
};
