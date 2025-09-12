//G(a,b)=G(b,a%b);  if(b==0) return a
#include <iostream>
#include <vector>
using namespace std;

int GCD(int a,int b){
    if(b==0) return a;
    else return GCD(b,a%b);
}

int main(){
    int n;
    cin >> n;
    while(n--){
        int a,b;
        cin >> a >> b;
        int res=GCD(a,b);
        cout << res << endl;
    }
    return 0;
}
