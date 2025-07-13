//题意：一个数组，把数组中的元素分为k组，目的:让每组的数字和的最大差值最小， 返回数字和最大的值
//把数组元素分配给k个数。 递归是：遍历数组    每一层可以有k种选择。 递归结束条件就是遍历到最后一个了，保存当前的[ ],分配情况（每组的总和的数组）
class Solution {
private:
    int result=10000000;
    void backtracking(vector<int>& cookies,vector<int>& curchild,int index){
        if(index==cookies.size()){  //确实直接记录最大元素就可以，记录每次的最大元素， result保存的是最小的最大元素
            int cur=*max_element(curchild.begin(),curchild.end());
            if(cur<result){
                result=cur;
            }
            return ;
        }
        //不需要外层循环，每次index+1就是在执行外部循环
        for(int j=0;j<curchild.size();j++){
            if (curchild[j] + cookies[index] >= result) continue; //剪枝：如果当前分配已不可能更优，跳过
            curchild[j]+=cookies[index];
            backtracking(cookies,curchild,index+1);
            curchild[j]-=cookies[index];

            if (curchild[j] == 0) break;  //// 剪枝：如果当前孩子未分配过饼干，跳过后续孩子（避免重复对称解）
        }
        return ;
    }

public:
    int distributeCookies(vector<int>& cookies, int k) {
        vector<int> curchild(k,0);
        backtracking(cookies,curchild,0);
        return result;
    }
};