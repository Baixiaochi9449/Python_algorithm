class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        //stack 进来大数，依次移除栈顶元素，压入大数。 进来小数，直接进栈 
        int n= temperatures.size();
        stack<int> sta;
        vector<int> ans(n);
        for(int i=0;i<n;i++){
            while(!sta.empty() && temperatures[sta.top()]<temperatures[i]){
                int temp=sta.top();
                ans[temp]=i-temp;
                sta.pop();
            }
            sta.push(i);
        }
        return ans;
    }
};
