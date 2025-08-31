class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        // 【1，5-1】 这个几个站有2个人， 【3，7-1】又+3个人  差分操作
        //判断每个站台的人数 不能超过4个人---求前缀和
        vector<int> diff(1001,0);
        vector<int> res(1001,0);
        for(auto trip :trips){
            int num=trip[0];
            int from=trip[1];
            int to=trip[2];
            diff[from]+=num;
            diff[to]-=num;
        }
        res[0]=diff[0];
        if(res[0]>capacity) return false;
        for(int i=1;i<1001;i++){
            res[i]=res[i-1]+diff[i];
            if(res[i]>capacity) return false;
        }
        return true;
    }
};
