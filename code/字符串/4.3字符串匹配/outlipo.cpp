#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<int> get_next(const string& pattern) {
    int m = pattern.size();
    vector<int> next(m, 0);
    int j = 0;
    for (int i = 1; i < m; i++) {
        while (j > 0 && pattern[i] != pattern[j]) {
            j = next[j - 1];
        }
        if (pattern[i] == pattern[j]) {
            j++;
        }
        next[i] = j;
    }
    return next;
}

int run_KMP(const vector<int>& next, const string& pattern, const string& text) {
    int n = text.size();
    int m = pattern.size();
    int j = 0;
    int count = 0;
    for (int i = 0; i < n; i++) {
        while (j > 0 && text[i] != pattern[j]) {
            j = next[j - 1];
        }
        if (text[i] == pattern[j]) {
            j++;
        }
        if (j == m) {
            count++;
            j = next[j - 1]; // 回退j以允许重叠匹配
        }
    }
    return count;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int T;
    cin >> T;
    while (T--) {
        string pattern, text;
        cin >> pattern >> text;
        vector<int> next = get_next(pattern);
        int count = run_KMP(next, pattern, text);
        cout << count << '\n';
    }
    return 0;
}