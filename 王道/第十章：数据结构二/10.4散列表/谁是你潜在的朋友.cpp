#include <iostream>
#include <map>
#include <vector>
using namespace std;

int main(){
    int n,m;
    while(cin >> n >> m){
        vector<int> person(n);
        map<int,int> books;
        for(int i=0;i<n;i++){
            cin >> person[i] ;
            books[person[i]]++;
        }
        for(int i=0;i<n;i++){
            if(books[person[i]]>1){
                cout << books[person[i]]-1 <<endl;
            }
            else{
                cout << "BeiJu" << endl;
            }
        }
    }
    return 0;
}