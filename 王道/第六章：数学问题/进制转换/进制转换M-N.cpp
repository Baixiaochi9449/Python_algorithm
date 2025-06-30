#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int ChartoInt(const char& c){
    if (c>='0' && c<='9'){
        return c-'0';
    }
    else{
        return c-'A'+10;
    }
}

char InttoChar(const int& n){
    if (n>=0 && n<=9){
        return n+'0';
    }
    else{
        return n+'A'-10;
    }
}


int main(){
    int M,N;
    string number;
    while(cin >> M >> N >> number){
        string result="";
        for (int i=0;i<number.size();){
            int remainder=0;
            for(int j=i;j<number.size();j++){
                int temp=ChartoInt(number[j]);
                int r=(M*remainder+temp)%N;
                char ch=InttoChar((M*remainder+temp)/N);
                number[j]=ch;
                remainder=r;
            }
            char c=InttoChar(remainder);
            result+=c;
            if(number[i]=='0') i++;
        }
        reverse(result.begin(),result.end());
        int i;
        for(i=0;i<result.size();i++){
            if(result[i]!='0'){
                break;
            }
        }
        cout << result.substr(i);
    }
    return 0;
}