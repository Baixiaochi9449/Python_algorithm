#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

long long n,k,l;

bool check(long long mid,vector<long long>& nums){
    long long result=0;
    if(mid>n) return false;
    if(mid<=n){
        for(long long i=n-mid;i<n;i++){
            if(nums[i]<mid) result+=(mid-nums[i]);
            if (mid - nums[i] > k) return false;
        }
        if(result<=k*l) return true;
        else return false;
    }
    return false;
}

int main(){
    while(cin >> n >> k >> l){
        vector<long long> nums(n);
        for(long long i=0;i<n;i++){
            cin >> nums[i];
        }
        sort(nums.begin(),nums.end());
        
        long long l=0,r=2e5;
        while(l<r){
            long long mid=l+r+1 >>1;
            if(check(mid,nums))  l=mid;
            else r=mid-1;
        }
        cout << l << endl;
    }
    return 0;
}