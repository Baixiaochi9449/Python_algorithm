class Solution {
public:

    vector<int> canSeePersonsCount(vector<int>& heights) {
        //单调栈牛逼啊。 要求的是，当前的数 与 下一个更大的数 之间的数的个数。 但是并不是所有的都要记录，如果做到这一点？就是因为倒序加入， 用栈， 矮的都挤掉了，栈里面的都是升序（从下到上 是从大到小） ，所以就直接在挤掉的时候直接算 
        stack<int> sta;  //存储下标
        int n=heights.size();
        vector<int> ans(n);  //存储下标
        vector<int> res(n,0);
        for(int i=n-1;i>=0;i--){
            int count=0;
            while(!sta.empty() && sta.top()<heights[i]){
                sta.pop();
                count++;
            }
            if(sta.empty()) res[i]=count;  //右边没有比它高的，所以不加1
            else res[i]=count+1; //把那个右边比它高的也算上
            sta.push(heights[i]);
        }
        return res;
    }
};
