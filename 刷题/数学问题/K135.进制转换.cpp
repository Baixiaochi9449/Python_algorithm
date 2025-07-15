#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int chartoint(char x){
    if(x>='0' && x<='9'){
        return x-'0';
    }
    else{
        return x-'A'+10;
    }
}
char inttochar(int a){
    if(a>=0 && a<=9){
        return a+'0';
    }
    else{
        return a-10+'A';
    }
}

int main(){
    int a,b,M;
    while(cin >>M >>a >> b){
        long long sum=a+b;
        int N=10;
        string str=to_string(sum);
        string result="";
        for(int i=0;i<str.size();){
            int remainder=0;
            for(int j=i;j<str.size();j++){
                int r=(N*remainder+chartoint(str[j]))%M;
                int t=(N*remainder+chartoint(str[j]))/M;
                str[j]=inttochar(t);
                remainder=r;
            }
            if(str[i]=='0'){
                i++;
            }
            result.push_back(inttochar(remainder));
        }
        reverse(result.begin(),result.end());
        for(int i=0;i<result.size();i++){
            cout << result[i];
            if(i==result.size()-1){
                cout << endl;
            }
        }
    }
}