//先找到所有小于ai的数，再减去小于ai但是有矛盾的数
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int n,m;
    while(cin >> n >> m){
        vector<int> a(n+1,0);
        vector<int> b(n+1,0);
        for(int i=1;i<=n;i++){
            cin >> a[i];
            b[i]=a[i];
        }
        sort(b.begin(),b.end());  //b的作用仅仅用于lower_bound()
        
        vector<int> c(n+1,0);
        while(m--){
            int x,y;  //下标
            cin >> x >> y;
            if(a[x]>a[y]) c[x]++;  //存储下标
            if(a[x]<a[y]) c[y]++;
        }
        for(int i=1;i<=n;i++){
            auto it = lower_bound(b.begin(),b.end(),a[i]);  //找比a[i]小的数的个数
            int k =it-b.begin();
            cout << k-1 -c[i] <<" ";
        }
    }
    return 0 ;
}