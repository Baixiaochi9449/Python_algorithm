class Solution {
public:
    static bool compare(int a,int b){
        return a>b;
    }
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        //ºÜ¼òµ¥°¡
        int sum=0;
        for(int i=0;i<apple.size();i++){
            sum+=apple[i];
        }
        // return sum;
        sort(capacity.begin(),capacity.end(),compare);

        int res=0;
        for(int i=0;i<capacity.size();i++){
            if(sum<=0) break;
            sum-=capacity[i];
            res++;
        }

        return res;
    }
};
