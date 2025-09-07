class Solution {
    public:
        double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
            //我只会暴力找中位数
            vector<int> res;
            int i=0,j=0;
            while(i<nums1.size() && j<nums2.size()){
                if(nums1[i]<nums2[j]){
                    res.push_back(nums1[i]);
                    i++;
                }
                else{
                    res.push_back(nums2[j]);
                    j++;
                }
            }
            while(i<nums1.size()){
                res.push_back(nums1[i]);
                i++;
            }
            while(j<nums2.size()){
                res.push_back(nums2[j]);
                j++;
            }
            if(res.size()%2==0){
                int mid=res.size()/2;
                double result=((double)res[mid-1]+(double)res[mid])/2;  //整数除法会丢失小数部分
                return result;
            }
            else{
                int mid=res.size()/2;
                return (double)res[mid];
            }
        }
    };