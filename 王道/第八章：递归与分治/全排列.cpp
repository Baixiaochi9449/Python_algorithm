#include <iostream>
#include <string>
using namespace std;

void FullRank(string pre,string str){
    if(str.size()==1){
        cout << pre+str <<endl;
    }

    string nextpre="";
    string nextstr="";
    for(int i=0;i<str.size();i++){
        nextpre=pre+str[i];
        nextstr=str;
        nextstr.erase(i,1);
        FullRank(nextpre,nextstr);
    }
}

int main() {
   string str;
   while(cin >> str){
        FullRank("",str);
   }
   return 0;
}
