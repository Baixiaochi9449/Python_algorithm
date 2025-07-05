#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct mice{
    int w;
    string color;
    mice(int w,string color):w(w),color(color){};
};

bool compare(mice a,mice b){
    if(a.w>b.w){
        return true;
    }
    return false;
}

int main(){
    int n;
    while(cin >> n){
        vector<mice> mouse;
        for(int i=0;i<n;i++){
            int w;
            string col;
            cin >> w >> col;
            mice m=mice(w,col);
            mouse.push_back(m);
        }
        sort(mouse.begin(),mouse.end(),compare);
        for(int i=0;i<n;i++){
            cout << mouse[i].color << endl;
        }
    }
    return 0;
}