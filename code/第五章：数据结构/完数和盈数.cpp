#include <iostream>
#include <vector>
using namespace std;

int SUM(const int& a){
    int sum=0;
    for (int i=1;i<a;i++){
        if(a%i==0){
            sum+=i;
        }
    }
    return sum;
}

int main(){
    vector<int> E,G;
    for(int i=2;i<=60;i++){
        if(SUM(i)==i){
            E.push_back(i);
        }
        if(SUM(i)>i){
            G.push_back(i);
        }
    }
    cout << "E:";
    for (int i=0;i<E.size()-1;i++){
        cout << E[i] <<' ' ;
    }
    cout << E[E.size()-1] << '\n';
    cout << "G:";
    for (int i=0;i<G.size()-1;i++){
        cout << G[i] <<' ' ;
    }
    cout << G[G.size()-1] << '\n';

    return 0;

}