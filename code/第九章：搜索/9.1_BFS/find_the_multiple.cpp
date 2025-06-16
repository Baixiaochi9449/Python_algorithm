#include <iostream>
#include <queue>
#include <cstdio>
using namespace std;

long long MAX=100000;

long long  find_number(int n){
    queue<long long> Que;
    Que.push(1);   //最后的数是由 1 和  0组成的， 就只需要想怎么变成 1和0的数，跟n没有关系
    while(!Que.empty()){
        long long current=Que.front();
        Que.pop();
        if(current%n==0){
            return current;
        }
        Que.push(current*10);
        Que.push(current*10+1);
    
    }
    return -1;
}

int main(){
    int n;
    while(cin >> n){
        cout << find_number(n) << endl;
    }
    return 0;
}
