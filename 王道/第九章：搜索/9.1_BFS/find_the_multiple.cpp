#include <iostream>
#include <queue>
#include <vector>

using namespace std;
struct Sta{
    string str;
    int remainder;
    Sta(string s,int r):str(s),remainder(r){}
};

bool find(int n){
    queue<Sta> number;
    int reaminder=1%n;
    Sta origin("1",reaminder);
    number.push(origin);

    while(!number.empty()){
        Sta current=number.front();
        number.pop();

        if(current.remainder%n==0){
            cout << current.str << endl;
            return true;
        }
        int next=current.remainder%n;

        number.push({current.str+"0",next*10});
        number.push({current.str+"1",next*10+1});
    }    
    return false;
}

int main(){
    int n;
    while(cin >> n ){
        if(n==0){
            break;
        }
        find(n);
    }
    return 0;
}