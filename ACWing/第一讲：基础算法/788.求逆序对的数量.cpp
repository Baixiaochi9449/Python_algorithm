#include <iostream>
using namespace std;
const int N = 100010;
int a[N];
int temp[N];

long long find(int a[], int l, int r){
    if(l >= r) return 0;
    int mid = l + (r - l >> 1);
    long long res = 0;
    res += find(a, l, mid);
    res += find(a, mid + 1, r);

    int i = l, j = mid + 1, k = 0;
    while(i <= mid && j <= r){
        if(a[i] <= a[j]) temp[k++] = a[i++];
        else
        {
            temp[k++] = a[j++];
            res += mid - i + 1;
        }
    }
    while(i <= mid) temp[k++] = a[i++];
    while(j <= r) temp[k++] = a[j++];

    for(i = l,k = 0;i <= r;i++)
        a[i] = temp[k++];
    return res;


}

int main(){
    int n;
    cin >> n;
    for(int i = 0; i < n;i++){
        cin >> a[i];
    }
    cout << find(a, 0 ,n - 1);
}

