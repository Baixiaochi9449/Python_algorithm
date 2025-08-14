class Solution {
public:
    int candy(vector<int>& ratings) {
        int n=ratings.size();
        int res=0;
        int i=0,j=1;
        vector<int> candies(n,1);
        while(j<n){
            if(ratings[i]<ratings[j] && candies[i]>=candies[j]) candies[j]=candies[i]+1; //这样是正确的，因为candies【i】不会再变
            i++;
            j++;
        }
        i=n-2,j=n-1;
        while(i>=0){
            if(ratings[i]>ratings[j] && candies[i]<=candies[j]) candies[i]=max(candies[i],candies[j]+1); //使用最大值，为了不破坏已经满足条件的结果
            i--;
            j--;
        }
        for(int i=0;i<n;i++){
            res+=candies[i];
        }
        return res;
    }
};