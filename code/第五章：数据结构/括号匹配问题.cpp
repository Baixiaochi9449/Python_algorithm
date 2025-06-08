#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main(){
    string s;
    getline(cin,s);
    stack<char> st;
    cout << s << '\n';
    int n=s.size();
    for (int i=0;i<n;i++){
        if(s[i]=='('){
            st.push(s[i]);
            cout << " ";
        }
        else if(s[i]==')'){
            if(st.empty()){
                cout << "?";
            }
            else{
                st.pop();
                cout << " ";
            }
        }
        else{
            cout << ' '; 
        }
    }
    if(!st.empty()){
        cout << "$";
    }
    return 0;
}