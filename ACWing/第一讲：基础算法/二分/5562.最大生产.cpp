#include <iostream>
#include <vector>
using namespace std;

bool check(long long mid,long long sum_a,long long sum_b,long long k,vector<long long>& a,vector<long long>& b){
    long long n=a.size();
    if(mid*sum_a-sum_b>k) return false;
    long long result=0;
    for(long long i=0;i<n;i++){
      if(mid*a[i]-b[i]>0) result+=mid*a[i]-b[i];
      if(result>k) return false;
    }
    
    return true;;
}

int main(){
  long long n,k;
  while(cin >> n >> k){
    vector<long long> a(n);
    long long sum_a=0;
    for(long long i=0;i<n;i++){
      cin >> a[i];
      sum_a+=a[i];
    }
    vector<long long> b(n);
    long long sum_b=0;
    for(long long i=0;i<n;i++){
      cin >> b[i];
      sum_b+=b[i];
    }
    //二分找的一定是答案，如果没有答案怎么办？
    
    long long l=0,r=2e9;
    while(l<r){
      long long mid=(l+r+1)/2;
      if(check(mid,sum_a,sum_b,k,a,b))  l=mid; //当前的mid,k够用，所以mid还能更大;
      else r=mid-1;
    }
    if(r*sum_a-sum_b>k) cout << 0 << endl;
    else cout << r << endl;
  }
  return 0;
}