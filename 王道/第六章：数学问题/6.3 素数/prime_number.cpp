#include <iostream>
#include <vector>
using namespace std;

vector<int> prime;
vector<bool> isprime;

void initial(int n) {
    isprime.resize(n, true);
    isprime[0] = isprime[1] = false;
    for (int i = 2; i < n; i++) {
        if (!isprime[i]) continue;
        prime.push_back(i);
        for (long long j = (long long)i * i; j < n; j += i) {
            isprime[j] = false;
        }
    }
}

int main() {
    const int MAX_SIZE = 100000; // 足够大的范围，确保能包含前 9384 个素数
    initial(MAX_SIZE);

    int k;
    while (cin >> k) {
        if (k <= 0 || k > prime.size()) {
            cout << "k is out of range!" << endl;
        } else {
            cout << prime[k - 1] << endl;
        }
    }
    return 0;
}