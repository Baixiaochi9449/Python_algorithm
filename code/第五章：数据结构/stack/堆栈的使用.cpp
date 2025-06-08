#include <iostream>
#include <stack>
using namespace std;

int main(){
    int n;
    while(cin >> n){
        stack<int> number;
        for(int i=0;i<n;i++){
            char symbol;
            cin >> symbol;
            if(symbol=='A'){
                if(!number.empty()){
                    cout << number.top() << endl;
                }
                else{
                    cout << 'E' <<endl;
                }
            }
            else if(symbol=='O'){
                if(!number.empty()){
                    number.pop();
                }
            }
            else{
                int temp;
                cin >> temp;
                number.push(temp);
            }
            
        }
    }
    return 0;
}