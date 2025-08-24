#include <iostream>
#include <string>
#include <stack>
#include <unordered_map>
using namespace std;

int operate(char op, int nums1, int nums2) {
    if (op == '+') return nums1 + nums2;
    else if (op == '-') return nums1 - nums2;
    else if (op == '*') return nums1 * nums2;
    else return nums1 / nums2; // 默认 /
}

int main() {
    unordered_map<char, int> priority = {
        {'*', 1}, {'/', 1}, {'+', 0}, {'-', 0}
    };
    string s;
    getline(cin, s);
    stack<char> operater;
    stack<int> numbers;

    for (int i = 0; i < (int)s.size(); i++) {
        char a = s[i];

        // 跳过空格
        if (a == ' ') continue;

        // 遇到数字（可能是多位数）
        if (a >= '0' && a <= '9') {
            int sum = 0;
            while (i < (int)s.size() && s[i] >= '0' && s[i] <= '9') {
                sum = sum * 10 + (s[i] - '0');
                i++;
            }
            numbers.push(sum);
            i--; // for 循环还会 i++，所以这里回退一步
        }
        // 遇到左括号
        else if (a == '(') {
            operater.push(a);
        }
        // 遇到右括号
        else if (a == ')') {
            while (!operater.empty() && operater.top() != '(') {
                char op = operater.top(); operater.pop();
                int nums2 = numbers.top(); numbers.pop();
                int nums1 = numbers.top(); numbers.pop();
                numbers.push(operate(op, nums1, nums2));
            }
            if (!operater.empty()) operater.pop(); // 弹出 '('
        }
        // 遇到运算符
        else if (a == '+' || a == '-' || a == '*' || a == '/') {
            while (!operater.empty() && operater.top() != '(' &&
                   priority[operater.top()] >= priority[a]) {
                char op = operater.top(); operater.pop();
                int nums2 = numbers.top(); numbers.pop();
                int nums1 = numbers.top(); numbers.pop();
                numbers.push(operate(op, nums1, nums2));
            }
            operater.push(a);
        }
    }

    // 处理剩下的运算符
    while (!operater.empty()) {
        char op = operater.top(); operater.pop();
        int nums2 = numbers.top(); numbers.pop();
        int nums1 = numbers.top(); numbers.pop();
        numbers.push(operate(op, nums1, nums2));
    }

    cout << numbers.top() << endl;
    return 0;
}
