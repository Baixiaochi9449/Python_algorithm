//行和行对调
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<string> strs(n);
    vector<vector<int>> arr(n,vector<int>(n));
    for(int i=0;i<n;i++){
        cin >> strs[i];
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            arr[i][j]=strs[i][j]-'0';
        }
    }
    for(int j=0;j<n-1;j++){
        //先找到第j列中，从j行到最后的的行中的最大的数所在的行
        int max_sum=0;
        int find_i=j;
        for(int i=j;i<n;i++){
            if(arr[i][j]>max_sum){
                max_sum=arr[i][j];
                find_i=i;
            }
        }
        //开始调换 第find_i行和第j行
        for(int k=0;k<n;k++){
            int temp=arr[find_i][k];
            arr[find_i][k]=arr[j][k];
            arr[j][k]=temp;
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout << arr[i][j];
        }
        cout << endl;
    }
    return 0;
}
