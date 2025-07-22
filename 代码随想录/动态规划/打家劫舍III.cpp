#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
    vector<int> v(3);
    for (int i=0;i<3;i++){
        cin  >> v[i];
    }
    sort(v.begin(),v.end());
    int ans = 0;
    for(int i=0;i<3;i++){
        if(v[i]==v[0]){
            ans+=1;
        }
        else if(v[i]==v[1]){
            ans+=2;
        }
        else if(v[i]==v[2]){
            ans+=3;
        }
        else{
            ans+=0;
        }
    }
    cout << ans << endl;
    
}