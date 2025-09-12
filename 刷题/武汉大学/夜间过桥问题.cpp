//本质上就是，让最快的一个人/2个人带 最慢的2个人过河
//2种情况，让最快的带 慢1 和慢2 过河， （带2个慢的人过去后再回来为一轮）
//情况二：让最快的2个人带 慢1慢2，  快12过，1回， 慢12过， 2回
//2种情况取一个最小值，直到剩下的人=0
//还有3种初始的特殊情况，只剩1个人，只剩2个人，只剩3个人
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }
    sort(arr.begin(),arr.end()); //从小到大排序
    int res=0;
    int left=n;
    while(left>0){
        if(left==1) {
            res+=arr[0];
            left--;
        }
        else if(left==2){
            res+=arr[1];
            left-=2;
        }
        else if(left==3) {
            res+=arr[0]+arr[1]+arr[2];
            left-=3;
        }
        else{
            int num1=arr[0]*2+arr[left-1]+arr[left-2];
            int num2=arr[0]+arr[1]*2+arr[left-1];
            res+=min(num1,num2);
            left-=2;
        }
    }
    cout << res << endl;
    return 0;
}