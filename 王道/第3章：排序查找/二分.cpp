#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool search(vector<int> vec,int t){
    int sum=vec.size()-1;
    int left=0;
    int right=sum;
    while(left<=right){
        int middle=(left+right)/2;
        if(t<vec[middle]){
            right=middle-1;
        }
        else if(t>vec[middle]){
            left=middle+1;
        }
        else if(t==vec[middle]) return true;
    }
    return false;
}


int main(){
    int n;
    while(cin >> n){
        vector<int> vec(n);
        for(int i=0;i<n;i++){
            cin >> vec[i];
        }
        int m;
        cin >> m;
        while(m--){
            int t;
            cin >> t;
            sort(vec.begin(),vec.end());
            if(search(vec,t)) cout << "YES" <<endl;
            else cout << "NO" << endl;
        }
    }
    return 0;
}