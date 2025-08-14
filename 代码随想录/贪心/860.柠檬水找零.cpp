class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int count_5=0; //记录手上有的5元的数量
        int count_10=0; //记录手上10元的数量
        for(int i=0;i<bills.size();i++){
            if(bills[i]==5) count_5++;
            if(bills[i]==10){
                if(count_5==0) return false;
                else{
                    count_5--;
                    count_10++;
                }
            } 
            if(bills[i]==20){
                if(count_10>0 && count_5>0){  //一定优先使用10快的
                    count_10--;
                    count_5--;
                }
                else if(count_10==0 && count_5>=3) {
                    count_5-=3;
                }
                else return false;
            }
        }
        return true;
    }
};