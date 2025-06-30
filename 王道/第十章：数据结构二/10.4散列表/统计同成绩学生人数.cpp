#include <iostream>
#include <map>

using namespace std;

int main(){
    int n;
    while(cin >> n){
        if(n==0){
            break;
        }
        map<int,int> count;
        for(int i=0;i<n;i++){
            int temp;
            cin >> temp;
            count[temp]++;
        }
        int grades;
        cin >> grades;
        if(count.count(grades)){
            cout << count[grades] << endl;
        }
        else{
            cout << 0 <<endl;
        }
    }
    return 0;
}