class Solution {
    public:
        int trap(vector<int>& height) {
            //i左边柱子的最大高度=max(左边柱子最大高度，自身的高度)
            //计算出每个位置左边的最大高度，右边的最大高度， 自身位置上的雨水=min(左，右)-h[i]
            int n = height.size();
            vector<int> leftmax(n),rightmax(n);
            leftmax[0]=height[0];
            for(int i=1;i<n;i++){
                leftmax[i]=max(leftmax[i-1],height[i]);
            }
            rightmax[n-1]=height[n-1];
            for(int i=n-2;i>=0;i--){
                rightmax[i]=max(rightmax[i+1],height[i]);
            }
            int res=0;
            for(int i=0;i<n;i++){
                int temp=min(rightmax[i],leftmax[i])-height[i];
                if(temp>0) res+=temp;
            }
            return res;
        }
    };