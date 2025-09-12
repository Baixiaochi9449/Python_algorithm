#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

int main(){
    int n;
    cin >> n;
    while(n--){
        vector<int> res;
        int num;
        cin >> num;
        for(int i=1;i<=sqrt(num);i++){
            if(num%i==0) {
                res.push_back(i);
                if(i!=num/i)  res.push_back(num/i);
            }
        }
        sort(res.begin(),res.end());
        for(int i=0;i<res.size();i++){
            cout << res[i] << ' ';
        }
        cout << endl;
    }
    return 0;
}