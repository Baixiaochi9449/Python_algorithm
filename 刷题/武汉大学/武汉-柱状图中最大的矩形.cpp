//�������������� �߶�Ҫ�� ˫ָ������߿�ʼ����������������¼������ġ�
//����Ҫ�ĳ�ʶ��������ǰ�ƶ�
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }

    int res=0;
    if(n==1) res=arr[0];
    else{
        //����
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int min_h=arr[i];
                for(int k=i;k<=j;k++){
                    min_h=min(min_h,arr[k]);
                    
                }
                int cur=min_h*(j-i+1);
            
                res=max(res,cur);
            }
        }
    }
    cout << res << endl;
}
