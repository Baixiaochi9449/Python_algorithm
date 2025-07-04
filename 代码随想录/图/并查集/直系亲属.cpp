//儿子有2个父母，父母有1个儿子，所以存储儿子节点，辈分小的在上面
//读取的时候初始化son[A]=B   字符可以直接当做数字用是 ASKII码 ，存储高度 height[A]=1+height[B];
//int Find(int x,int y,int count） 找x和y之间的距离， 递归直到heght[x]==height[y]; 注意其中的情况
//最后输出的时候，先判断高度，选择是parent还是son，再根据count来决定几个grant

#include <iostream>
#include <vector>
#include <string>

using namespace std;
int MAX = 101;
vector<int> Son(MAX);
vector<int> height(MAX);


void init() {
    for (int i = 0; i < MAX; i++) {
        Son[i] = i;
        height[i] = 0;
    }
}

int find(int a, int b, int num) {
    //第一种情况应该是夫妻关系。双方有共同的儿子，且其中之一的儿子不是自身，因为 最顶层的儿子的儿子是自己
    if (Son[a] == Son[b] && a != b && Son[a] != a && Son[b] != b) return -1;

    if (height[a] < height[b]) {
        b = Son[b];
        num++;
        return find(a, b, num);
    }
    if (height[a] > height[b]) {
        a = Son[a];
        num++;
        return find(a, b, num);
    }
    if (height[a] == height[b] & a == b) {
        return num;
    }
    return -1;
}

//处理字符的时候要先把字符变成 数字
int main() {
    int n, m;
    while (cin >> n >> m) {
        init();
        string str;
        while (n--) {
            cin >> str;
            int son = str[0] - 'A';
            if (str[1] != '-') {
                int p1 = str[1] - 'A';
                Son[p1] = son;
                height[p1] = 1 + height[son];
            }
            if (str[2] != '-') {
                int p2 = str[2] - 'A';
                Son[p2] = son;
                height[p2] = 1 + height[son];
            }
        }
        while (m--) {
            string str2;
            cin >> str2;
            int a = str2[0] - 'A';
            int b = str2[1] - 'A';
            int result = find(a, b, 0);
            // cout << result <<endl;
            if (result < 0) {
                cout << '-' << endl;
            } else {

                if (height[a] > height[b]) { //parent系列
                    if (result == 1) {
                        cout << "parent" << endl;
                    }
                    if (result == 2) {
                        cout << "grandparent" << endl;
                    }
                    if (result > 2) {
                        string res = "grandparent";
                        while (result > 2) {
                            res = "great-" + res;
                            result--;
                        }
                        cout << res << endl;
                    }
                }

                if (height[a] < height[b]) { //son系列
                    if (result == 1) {
                        cout << "child" << endl;
                    }
                    if (result == 2) {
                        cout << "grandchild" << endl;
                    }
                    if (result > 2) {
                        string res = "grandchild";
                        while (result > 2) {
                            res = "great-" + res;
                            result--;
                        }
                        cout << res << endl;
                    }
                } 
                
            }

        }
    }
    return 0;
}