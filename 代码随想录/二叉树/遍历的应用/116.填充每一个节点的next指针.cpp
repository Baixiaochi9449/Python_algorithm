/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/
//逐层遍历，记录每一层循环的数量。 开始新的一层的时候定义两个节点，pre cur.开始pre指向第一个节点。
class Solution {
public:
    Node* connect(Node* root) {
        if (root == nullptr) return root;
        queue<Node*> que;
        que.push(root);
        while (!que.empty()) {
            int size = que.size();
            Node* pre = nullptr;
            for (int i = 0; i < size; i++) {
                Node* cur = que.front();
                que.pop();
                if (pre != nullptr) {
                    pre->next = cur;
                }
                pre = cur;
                if (cur->left != nullptr) que.push(cur->left);
                if (cur->right != nullptr) que.push(cur->right);
            }
        }
        return root;
    }
};
    