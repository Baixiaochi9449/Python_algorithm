//行驶完后剩余的油量如果小于0，就return false
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        //从累计油量<0 的下一个位置开始
        int cursum=0;
        int totalsum=0;
        int start=0;
        for(int i=0;i<gas.size();i++){
            cursum+=(gas[i]-cost[i]);
            totalsum+=(gas[i]-cost[i]);
            if(cursum<0){
                start=i+1;
                cursum=0;
            }
        }
        if(totalsum<0) return -1;
        return start;
    }
};