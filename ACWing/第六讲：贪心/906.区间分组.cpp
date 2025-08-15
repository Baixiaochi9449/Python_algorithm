#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

bool compare(vector<int>& a, vector<int>& b){
    return a[0]<b[0]; //按照左边界排序
}

int main(){
    int n;
    cin >> n;
    vector<vector<int>> arr;
    for(int i=0;i<n;i++){
        int a,b;
        cin >> a >> b;
        arr.push_back({a,b});
    }
    sort(arr.begin(),arr.end(),compare);
    // priority_queue<int> que; //存放每个组的最大值
    priority_queue<int, vector<int>, greater<int>> que;   //优先级队列默认是大顶堆，这里要使用小顶堆，所以要添加...
    que.push(arr[0][1]); //先存放第一个元素的右边界
    int res=1;
    for(int i=1;i<arr.size();i++){
        int min_r=que.top();  //优先级队列要使用top  
        que.pop();
        if(arr[i][0]<=min_r){  //比最小的右边界，都有重叠，所以新开一个
            res++;
            que.push(min_r);
            que.push(arr[i][1]);
        }
        else{  //满足条件，存在不重叠的
            min_r=arr[i][1];
            que.push(min_r);
        }
    }
    cout <<res << endl;
    return 0;
    
}