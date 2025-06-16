//所有的节点都放到队列里
//状态（当前字符串，step） ,对于当前节点，要做的操作for( 交换一次所有的情况 ) ,数组不能记录string了，就用map


#include <iostream>
#include <string>
#include <unordered_map>
#include <queue>
using namespace std;

struct Sta{
    string str;
    int step;
    Sta(string str,int step):str(str),step(step){};
};

int BFS(string str,int n){
    queue<Sta> status;
    Sta ini(str,0);
    status.push(ini);
    unordered_map<string,bool> visit; 
    visit[str]=true;

    while(!status.empty()){
        Sta current = status.front();
        status.pop();
        if(current.str.find("2012")!= string::npos){
            return current.step;
        }

        for(int i=0;i<n-1;i++){
            Sta next=current;
            swap(next.str[i],next.str[i+1]);
            next.step+=1;
            if(next.str.find("2012")!= string::npos){
                return next.step;
            }
            if(!visit[next.str]){
            status.push(next);
            visit[next.str]=true;
            }
        }
    }
    return -1;
}

int main(){
    int n;
    string str;
    while(cin >> n >> str){
      cout << BFS(str,n) << endl;
    }
    return 0;
}
