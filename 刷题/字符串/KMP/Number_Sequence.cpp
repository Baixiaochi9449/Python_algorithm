#include <iostream>
#include <vector>

using namespace std;

vector<int> build_next(vector<int>& pattern){
    int n=pattern.size();
    vector<int> next(n,0);
    int i=0,j=0;
    for(i=0;i<pattern.size();i++){
        while(j>0 && pattern[i]!=pattern[j]){
            j=next[j-1]; //回退到 前一个元素的next位置
        }
        //找到相等的位置然后呢？
        if(pattern[i]==pattern[j]){
            j++;
        }
        next[i]=j;
    }
    return next;
}

int main(){
    int T;
    cin >> T;
    while(T--){
        int m,n;
        cin >> m >> n;
        vector<int> text(m);
        vector<int> pattern(n);
        for(int i=0;i<m;i++){
            cin >> text[i];
        }
        for(int i=0;i<n;i++){
            cin >> pattern[i];
        }

        vector<int> next = build_next(pattern);
        int i=0,j=0;
        while(i<m && j<n){
            while(j>0 && text[i]!=pattern[j]){
                j=next[j-1];
            }
            if(text[i]==pattern[j]){ //如果此时j=n-1就是最后一个已经匹配成功了
                j++;
            }
            
            if(j==n){
                cout << i-n+1 << endl;
                break;
            }
            i++;
        }
    }
    return 0;
}