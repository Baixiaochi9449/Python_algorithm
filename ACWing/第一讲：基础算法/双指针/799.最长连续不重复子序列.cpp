//区间里不能有重复的数。 
//unordered_map 记录出现的次数。 
//应该用滑动窗口：不包含重复字母的时候，窗口++ ， 包含了重复字符，窗口--
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }
    unordered_map<int,int> window;
    int l=0,r=0;
    int res=0;
    while(r<n){
        int cur=arr[r];
        r++;
        window[cur]++;
        while(window[cur]>1){ //把重复的删掉
            int d=arr[l];
            l++;
            window[d]--;
        }
        //此时窗口内都是不重复的
        res=max(res,r-l);
    }
    cout << res <<endl;
    return 0;
}
