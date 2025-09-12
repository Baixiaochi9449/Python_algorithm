#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstdio>
using namespace std;

int main(){
    int T;
    cin >> T;
    while(T--){
        int n;
        cin >> n;
        vector<string> strs(n);
        for(int i=0;i<n;i++){
            cin >> strs[i];
        }
        int res=0;
        for(int i=0;i<n;i++){
            string newstr=strs[i];
            reverse(newstr.begin(),newstr.end());
            for(int j=i+1;j<n;j++){
                if(newstr==strs[j]) res++;
            }
        }
        if(res) cout << res << endl;
        else cout << -1 << endl;
    }
    return 0;
}