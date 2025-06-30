#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

struct Record {
    string id;
    string sign_in;
    string sign_out;
};

int main() {
    int n;
    while (cin >> n) {
        vector<Record> records(n);
        for (int i = 0; i < n; ++i) {
            cin >> records[i].id >> records[i].sign_in >> records[i].sign_out;
        }

        // 找最早签到（开门人）
        string opener = records[0].id;
        string min_in = records[0].sign_in;
        // 找最晚签离（关门人）
        string closer = records[0].id;
        string max_out = records[0].sign_out;

        for (int i = 1; i < n; ++i) {
            // 比较签到时间（取最小值）
            if (records[i].sign_in < min_in) {
                min_in = records[i].sign_in;
                opener = records[i].id;
            }
            // 比较签离时间（取最大值）
            if (records[i].sign_out > max_out) {
                max_out = records[i].sign_out;
                closer = records[i].id;
            }
        }

        cout << opener << " " << closer << endl;
    }
    return 0;
}