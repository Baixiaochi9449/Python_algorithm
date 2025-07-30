#include <iostream>
#include <vector>
using namespace std;

int n,m;
bool check(int mid,vector<int> dishes){
    int result=0;
    for(int i=1;i<=100;i++){
        result+=dishes[i]/mid;
    }
    if(result>=n) return true;
    else return false;
}

int main(){
    cin >> n >> m;
    if(n>m){
        cout << 0 << endl;
        return 0;
    }
    vector<int> dishes(101,0);
    for(int i=0;i<m;i++){
        int temp;
        cin >> temp;
        dishes[temp]++;
    }
    int l=0,r=m/n;
    while(l<r){
        int mid=(l+r+1)/2;
        if(check(mid,dishes)) l=mid;
        else r=mid-1;
    }
    cout << l << endl;
    
    return 0;
}