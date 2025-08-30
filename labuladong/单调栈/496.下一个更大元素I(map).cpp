//把ans不存储到vector里，存储到map里，直接查元素数字，就知道下一个是什么了
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        //感觉nums1像在查询。 所以先求出nums2的ans数组
        stack<int> sta;
        int n=nums2.size();
        unordered_map<int,int> memo;
        vector<int> res;
        for(int i=n-1;i>=0;i--){
            while(!sta.empty() && sta.top()<=nums2[i]) { //移除栈中比 当前数 小的元素
                sta.pop();
            }
            if(sta.empty()) memo[nums2[i]]=-1;
            else memo[nums2[i]]=sta.top();
            sta.push(nums2[i]);
        }
        for(int i=0;i<nums1.size();i++){
            res.push_back(memo[nums1[i]]);
        }
         
        return res;
    }
};
