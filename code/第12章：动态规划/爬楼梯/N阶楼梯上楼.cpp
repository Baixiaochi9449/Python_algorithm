#include <iostream>
#include <unordered_map>
using namespace std;

int main(){
    int N;
    unordered_map<int,long long> dic;
    dic[0]=0;
    dic[1]=1;
    dic[2]=2;
    while (cin >> N) {
        for (int i=3;i<N+1;i++) {
            dic[i]=dic[i-1]+dic[i-2];
        }
        cout << dic[N] << "\n";
    }
    return 0;
}