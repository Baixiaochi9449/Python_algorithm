//搜索，从邻居节点，一个一个找
//三个邻居  （n+1,t+1）(n-1,t+1)(2*n,t+1)

#include <iostream>
#include <queue>
#include <cstdio>
using namespace std;

struct status{
    int n,t;
    status(int n,int t): n(n),t(t) {};
};

int find_k(int n,int k){
    queue<status> Sta;
    status ori(n,0);
    Sta.push(ori);
    int visit[100000];
    visit[n]=true;

    while(!Sta.empty()){
        status current = Sta.front();    //当前位置：把当前位置pop() ,对当前位置找所有的邻居位置，查询是不是目标位置,
        Sta.pop();
        //一个位置 能找另外3个位置
        for(int i=0;i<3;i++){  //要在每次循环开始，重新创建next状态
            status next(current.n,current.t+1);
            if(i==0){
                next.n+=1;
            }
            else if(i==1){
                next.n-=1;
            }
            else{
                next.n*=2;
            }

            if(next.n==k){     //找到了
                return next.t;
            }
            if(next.n<0 || next.n>100000 || visit[next.n]==true){  //找过了
                continue;
            }
            //新的位置 就压入队列，然后visit =true;
            Sta.push(next);
            visit[next.n]=true;   //把所有找到的新位置都变成true,因为已经压入栈了，之后肯定会处理的
        }
    
    }
    return -1;
}

int main(){
    int n,k;
    while(cin >> n >> k){
        cout << find_k(n,k);
    }
    return 0;
}