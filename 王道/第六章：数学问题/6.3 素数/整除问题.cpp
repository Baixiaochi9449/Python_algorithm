#include <iostream>
#include <vector>
#include <cmath>
#include <climits>
using namespace std;

vector<int> prime;
vector<bool> isprime;

struct number {
    int factor;
    int count = 0;
};

void initial(int n) {
    isprime.assign(n, true);   //在这里分配内存
    isprime[0] = isprime[1] = false;
    for (int i = 2; i < n; i++) {
        if (!isprime[i]) continue;
        prime.push_back(i);
        for (int j = i * i; j < n; j += i) {
            isprime[j] = false;
        }
    }
}

int main() {
    int n, a;
    while (cin >> n >> a) {
        // 初始化筛法，只需筛到 sqrt(a) + 1
        initial(sqrt(a) + 1);

        // 分解 a 的质因数
        vector<number> a_list;
        int temp_a = a;
        for (int p : prime) {
            if (p * p > temp_a) break;
            if (temp_a % p == 0) {
                number num;
                num.factor = p;
                num.count = 0;
                while (temp_a % p == 0) {
                    num.count++;
                    temp_a /= p;
                }
                a_list.push_back(num);
            }
        }
        if (temp_a > 1) {
            a_list.push_back({temp_a, 1});
        }

        // 计算 n! 中每个质因数的指数  找n的时候，只需要找 a的因数 的指数
        vector<number> n_list;
        for (auto &a_num : a_list) {
            int p = a_num.factor;
            int count = 0;
            int current = n;
            while (current > 0) {
                current /= p;
                count += current;
            }
            if (count > 0) {
                n_list.push_back({p, count});
            }
        }

        // 计算 k 的最大值
        int k = INT_MAX;
        for (auto &a_num : a_list) {
            int p = a_num.factor;
            int e = a_num.count;
            int count_p = 0;
            for (auto &n_num : n_list) {
                if (n_num.factor == p) {
                    count_p = n_num.count;
                    break;
                }
            }
            if (count_p == 0) {
                k = 0;
                break;
            }
            k = min(k, count_p / e);
        }

        cout << k << endl;
    }
    return 0;
}