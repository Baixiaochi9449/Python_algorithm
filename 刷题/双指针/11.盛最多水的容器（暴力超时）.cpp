class Solution {
    public:
        int maxArea(vector<int>& height) {
            //双指针，一点一点扩大，同时记录？如何双指针？只能暴力？
            int res=0;
            for(int i=0;i<height.size();i++){
                for(int j=i+1;j<height.size();j++){
                    int h=min(height[i],height[j]);
                    res=max(res,h*(j-i));
                }
            }
            return res;
        }
    };