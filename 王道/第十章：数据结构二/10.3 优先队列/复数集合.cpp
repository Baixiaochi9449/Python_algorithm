#include <iostream>
#include <queue>
#include <string>

using namespace std;

struct Complex {
    int real, imag;
    Complex(int a, int b) : real(a), imag(b) {}
    bool operator< (Complex c) const {      //重载 < 运算符
        return real*real + imag*imag < c.real*c.real + c.imag*c.imag;
    }
};

int main(){
    int n;
    while(cin >>n){
        string temp;
        priority_queue<Complex> Q;
        for(int i=0;i<n;i++){
            cin >> temp;
            if(temp=="Pop"){
                if(!Q.empty()){
                    int a ,b;
                    a=Q.top().real;
                    b=Q.top().imag;
                    cout << a<<"+"<<"i"<< b << endl;
                    Q.pop();
                    cout <<"SIZE = " << Q.size() <<endl;
                }
                else{
                    cout << "empty" <<endl;
                }
            }
            else{
                int a,b;
                scanf("%d+i%d",&a,&b);
                Complex t(a,b);
                Q.push(t);
                cout <<"SIZE = " << Q.size() <<endl;
            }
        }
    }
    return 0;
}