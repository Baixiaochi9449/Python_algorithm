#include <iostream>
#include <map>
#include <string>

using namespace std;

int main(){
    int n;
    while(cin >>n){
        map<string,string> student;
        string num,name,sex,old;
        for(int i=0;i<n;i++){
            cin >> num >> name >> sex >> old;
            student[num]=name+" "+sex+" "+old;
        }
        int m;
        cin >> m;
        map<string,string>::iterator it;
        while(m--){
            string temp;
            cin >> temp;
            it=student.find(temp);
            if(it != student.end()){ 
                cout << temp << " " << student[temp] << endl;
            }
            else{
                cout << "No Answer!" << endl;
            }
        }
    }
    return 0;
}