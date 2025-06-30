#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Rice{
    int price;
    int weight;
    int num;
};
const int MAX=100000;

int main(){
    int T=0;
    scanf("%d",&T);
    while(T--){
        int sum_p=0;
        int m_type=0;
        int number=0;
        scanf("%d%d",&sum_p,&m_type);
        vector<Rice> arr(m_type);
        vector<int> value(MAX);
        vector<int> weight(MAX);
        for (int i=0;i<m_type;i++){
            scanf("%d%d%d",&arr[i].price,&arr[i].weight,&arr[i].num);
            int j=1;
            while(arr[i].num>=j){
                value[number]=j*arr[i].price;
                weight[number]=j*arr[i].weight;
                arr[i].num-=j;
                j*=2;
                number+=1;
            }
            if (arr[i].num){
                value[number]=arr[i].num *arr[i].price;
                weight[number]=arr[i].num *arr[i].weight;
                number+=1;
            }
        }
        int new_m=value.size();
        vector<int> dp(sum_p+1,0);//可以全都先初始化为0

        for (int i=0;i<new_m;i++){
            for (int j=sum_p;j>=value[i];j--){
                dp[j]=max(dp[j],dp[j-value[i]]+weight[i]);
            }
        }
        printf("%d\n",dp[sum_p]);

    }
    return 0;
}

//充分使用vector  value.push_back()
// #include <cstdio>
// #include <iostream>
// #include <vector>
// using namespace std;

// struct Rice {
//     int price;
//     int weight;
//     int num;
// };

// int main() {
//     int T;
//     scanf("%d", &T);
//     while (T--) {
//         int sum_p, m_type;
//         scanf("%d%d", &sum_p, &m_type);
//         vector<Rice> arr(m_type);
//         vector<int> value; // 不预设大小
//         vector<int> weight;

//         for (int i = 0; i < m_type; i++) {
//             scanf("%d%d%d", &arr[i].price, &arr[i].weight, &arr[i].num);
//             int j = 1;
//             while (arr[i].num >= j) {
//                 value.push_back(j * arr[i].price); // 动态添加
//                 weight.push_back(j * arr[i].weight);
//                 arr[i].num -= j;
//                 j *= 2;
//             }
//             if (arr[i].num > 0) {
//                 value.push_back(arr[i].num * arr[i].price);
//                 weight.push_back(arr[i].num * arr[i].weight);
//             }
//         }

//         vector<int> dp(sum_p + 1, 0);
//         for (int i = 0; i < value.size(); i++) { // 直接使用实际大小
//             for (int j = sum_p; j >= value[i]; j--) {
//                 dp[j] = max(dp[j], dp[j - value[i]] + weight[i]);
//             }
//         }
//         printf("%d\n", dp[sum_p]);
//     }
//     return 0;
// }