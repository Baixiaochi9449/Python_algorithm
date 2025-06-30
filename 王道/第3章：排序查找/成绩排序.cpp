#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

struct student{
    int num;
    int score;
};
bool compare(const student& a,const student& b){
    if (a.score==b.score){
        return a.num<b.num;
    }
    else{
        return a.score<b.score;
    }
}

int main(){
    int n=0;
    while(scanf("%d",&n)!=EOF){
        vector<student> arr(n);
        for (int i=0;i<n;i++){
            scanf("%d%d",&arr[i].num,&arr[i].score);
        }
        sort(arr.begin(),arr.end(),compare);   //注意vetor的调用

        for (int i=0;i<n;i++){
            printf("%d %d\n",arr[i].num,arr[i].score);
        }
    }
}