//区间合并，并保存区间到合并后的数组中
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> arr; //合并后的区间

bool compare(vector<int>& a,vector<int>& b){
    return a[0]<b[0];
}

int thefirst(){
    int begin=arr[0][0];
    int end=arr[arr.size()-1][1];
    return end-begin;
}

bool check(int L){  //L是直线长度
    int n=arr.size();
    int begin=arr[0][0];
    int end=begin+L;
    if(end>=arr[n-1][1]) return true; //太大
    
    //找到第一根之间无法覆盖的第一个区间
    int i=0;
    while(i<n && arr[i][1]<=end){
        i++;
    }
    if(i>=n) return true;
    //现在聚焦在第i个区间上
    int nextbegin = max(arr[i][0], end); // 第二根直线的起点
    
    int nextend=nextbegin+L;
    if(nextend>=arr[n-1][1]) return true;
    else return false;
    
}

int thesecond(){
    //数组arr,k=2; 思路是，枚举直线长度
    int maxlenth=arr[arr.size()-1][1]-arr[0][0];
    if(arr.size()==1) return maxlenth;
    int l=0,r=maxlenth;
    while(l<r){
        int mid=(r+l)/2;
        if(check(mid)) r=mid;
        else l=mid+1;  //加1？会不会加的太多了？？？？
    }
    return l*2;
}

int thethird(int k){  //k个不等长的直线
    //思路：如果4个区间，k>=4,那么总和就是四个区间的长度。 k=3, 总和=sum+最小的1个空隙  ，k=2,总和=sum+最小的2个空隙，k=1,最小的4-k=3个空隙
    //所以把空隙从小到大排列
    int n=arr.size();
    vector<int> space;
    for(int i=0;i<n-1;i++){
        int temp=arr[i+1][0]-arr[i][1];
        space.push_back(temp);
    }
    sort(space.begin(),space.end()); //从小到大排序
    int sum=0;
    for(int i=0;i<n;i++){
        sum+=(arr[i][1]-arr[i][0]);
    }
    
    int res=0;
    for(int i=0;i<n-k;i++){
        res+=space[i];
    }
    return sum+res;
}


bool check2(int L,int k){
    int n=arr.size();
    int end=arr[0][0]; //end的初始值
    int i=0;  //直接判断能否处理到最后一个区间
    
    for(int j=0;j<k;j++){  //找剩下的k-1根直线
       if(i>=n) return true;
       int begin=max(end,arr[i][0]);  //取中间空隙的，还是区间上的
       end=begin+L;
       if(end>=arr[n-1][1]) return true;
       
       while(i<n && arr[i][1]<=end){
           i++;
       }
    }
    return false;
}

int theforth(int k){  //k个等长，确定了第一个的终端之后，后面的线摆放到哪里都能确定下来，所以还是用最后一根线的终点来判断
    int n=arr.size();
    int max_lenth=arr[n-1][1]-arr[0][0];
    if(n==1) return max_lenth;
    int l=0,r=max_lenth;
    while(l<r){
        int mid=(l+r)/2;
        if(check2(mid,k)) r=mid;
        else l=mid+1;
    }
    return l*k;
}
int main(){
    int n,k;
    cin >> n >> k;
    vector<vector<int>> nums;
    for(int i=0;i<n;i++){
        int a,b;
        cin >> a >> b;
        nums.push_back({a,b});
    }
    //开始区间合并
    sort(nums.begin(),nums.end(),compare);
    for(int i=0;i<n;i++){
        int begin=nums[i][0],end=nums[i][1];
        int j=i+1;
        while(j<n && nums[j][0]<=end){
            end=max(end,nums[j][1]);
            j++;
        }
        arr.push_back({begin,end});
        i=j-1;
    }
    //检查一下arr数组内容
    cout << "合并后的区间:"<< endl;
    for(int i=0;i<arr.size();i++){
        cout << arr[i][0] << ' '<<  arr[i][1] << endl;
    }
    
    cout << "第一题的答案:" << endl;
    int res1=thefirst();
    cout << res1 << endl;
    
    cout << "第二题的答案：" << endl;
    int res2=thesecond();
    cout << res2 << endl;
    
    cout << "第三题的答案：" << endl;
    int res3=thethird(k);
    cout << res3 << endl;
    
    cout << "第四题的答案：" << endl;
    int res4=theforth(k);
    cout << res4 << endl;
    
    return 0;
}