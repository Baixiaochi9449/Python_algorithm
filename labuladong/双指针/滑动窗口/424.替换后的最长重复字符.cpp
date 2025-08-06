//窗口的长度 right-left ， 窗口中最大元素的数量 x，  那么right-left-x >k 就开始减小窗口
class Solution {
    public:
        int characterReplacement(string s, int k) {
            int result=0;
            vector<int> countchar(26,0);
            int left=0,right=0;
            int curMaxCount=0;
    
            while(right<s.size()){
                int c = s[right]-'A';
                countchar[c]++;
                curMaxCount=max(curMaxCount,countchar[c]);
                right++;
                while(right-left-curMaxCount>k){   //区间计算，左闭右开。所以区间长度才能是 right-left;
                    int c = s[left]-'A';
                    countchar[c] --;
                    left++;
                }
                result=max(result,right-left);
            }
            return result;
        }
    };