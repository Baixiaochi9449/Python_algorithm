//只会暴力
#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> arr(n);
    vector<int> result;
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }
    for(int i=0;i<n;i++){
        int j=i-1;
        bool success=false;
        while(j>=0){
            if(arr[j]<arr[i]){
                result.push_back(arr[j]);
                success=true;
                break;
            }
            else j--;
        }
        if(!success) result.push_back(-1);
    }
    for(int i=0;i<n;i++){
        cout << result[i] << ' ';
    }
    return 0;
}