class Solution {
    public:
        int maxArea(vector<int>& height) {
            //双指针的做法就是直觉。i=0  j=height.size()-1  直觉上移动小的那个。 
            //为什么从两端开始？ 因为需要保证w和h都大，从两端开始能保证w一开始是最大的
            int l=0,r=height.size()-1;
            int res=0;
            while(l!=r){
                int h=min(height[l],height[r]);
                res=max(res,h*(r-l));
                if(height[l]<height[r]){
                    l++;
                }
                else{
                    r--;
                }
            }
            return res;
        }
    };