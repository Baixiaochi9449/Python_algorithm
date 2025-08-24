//有异或运算符啊
#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }
    int res=0;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            res=max(res,arr[i]^arr[j]);
        }
    }
    cout << res << endl;
    return 0;
}