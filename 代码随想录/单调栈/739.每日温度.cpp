class Solution {
    public:
        vector<int> dailyTemperatures(vector<int>& temperatures) {
            stack<int> sta;
            int n=temperatures.size();
            vector<int> res(n,0);
            for(int i=n-1;i>=0;i--){
                while(!sta.empty() && temperatures[sta.top()]<=temperatures[i]){
                    sta.pop();
                }
                if(sta.empty()) res[i]=0;
                else{
                    res[i]=sta.top()-i;
                }
                sta.push(i);
            }
            return res;
        }
    };