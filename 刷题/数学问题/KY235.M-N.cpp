#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int ChartoInt(char c){
    if(c>='0' && c<='9'){
        return c-'0';
    }
    else{
        return c-'A'+10;   //如果c='A' ,c-'A'=10 所以+10，因为我们要让A=10
    }
}

char InttoChar(int a){
    if(a>=0 && a<=9){
        return a+'0';
    }
    else{
        return a-10 +'A'; //如果a是10， 10-10=0  0+‘A’='A'   
    }
}

int main(){
    int M,N;
    string number;
    while(cin >> M >> N >> number){
        string result="";
        for(int i=0;i<number.size();){
            int remainder=0;
            for(int j=i;j<number.size();j++){
                int temp=ChartoInt(number[j]);
                int r=(M*remainder+temp)%N;
                int ch=(M*remainder+temp)/N;
                number[j]=InttoChar(ch);
                remainder=r;
            }
            result+=InttoChar(remainder);
            if(number[i]=='0'){
                i++;
            }
        }

        reverse(result.begin(),result.end());
        int i;
        for(i=0;i<result.size();i++){
            if(result[i]!='0') break;
        }

        cout << result.substr(i) << endl;
    }
    return 0;
}