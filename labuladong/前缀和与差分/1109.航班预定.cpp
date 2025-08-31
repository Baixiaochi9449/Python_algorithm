class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        //原nums是【0，0，0，0，0】 要在一个区间上++，先在差分数组上++，再对差分数组求前缀和
        vector<int> diff(n,0);
        for(int i=0;i<bookings.size();i++){
            int first=bookings[i][0]-1;
            int second=bookings[i][1]-1;
            int d=bookings[i][2];
            diff[first]+=d;
            if(second+1<n) diff[second+1]-=d;
        }
        vector<int> res(n);
        res[0]=diff[0];
        for(int i=1;i<n;i++){
            res[i]=res[i-1]+diff[i];
        }
        return res;
    }
};
