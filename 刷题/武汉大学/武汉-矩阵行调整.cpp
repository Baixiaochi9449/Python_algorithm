//�к��жԵ�
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
        //���ҵ���j���У���j�е����ĵ����е����������ڵ���
        int max_sum=0;
        int find_i=j;
        for(int i=j;i<n;i++){
            if(arr[i][j]>max_sum){
                max_sum=arr[i][j];
                find_i=i;
            }
        }
        //��ʼ���� ��find_i�к͵�j��
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
