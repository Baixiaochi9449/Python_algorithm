#include <iostream>
#include <map>
#include <string>
using namespace std;

//想法：遍历字符串，把所有的子串都存储到map中，出现过的就++， 最后遍历map输出value值>1的

int main(){
    string str;
    map<string,int> count;
    while(cin >>str){
        for(int i=0;i<str.size();i++){
            for(int j=i;j<str.size();j++){
                count[str.substr(i,j-i+1)]++;    这个map的用法
            }
        }
        map<string,int>::iterator it;
        for(it = count.begin();it!=count.end();it++){
            if(it->second>1){
                cout << it->first << ' ' << it->second << endl;
            }
        }
    }
    return 0;
}