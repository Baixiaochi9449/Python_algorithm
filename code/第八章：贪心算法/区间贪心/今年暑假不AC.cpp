#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct program{
    int begintime;
    int endtime;
};

bool compare(const program& a,const program& b){
    return a.endtime<b.endtime;
}
int main(){
    int MAX=100;
    int n=0;
    program arr[MAX];
    while(scanf("%d",&n)!=EOF){
        for (int i=0;i<n;i++){
            scanf("%d%d",&arr[i].begintime,&arr[i].endtime);
        }
        sort(arr,arr+n,compare);
        int count=0;
        int current_endtime=0;
        for (int i=0;i<n;i++){
            if(current_endtime<=arr[i].begintime){
                count++;
                current_endtime=arr[i].endtime;
            }
        }
        printf("%d\n",count);
    }
}