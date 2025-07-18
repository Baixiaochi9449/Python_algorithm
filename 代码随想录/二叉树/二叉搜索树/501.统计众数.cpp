class Solution {
private:
    vector<int> result;
    TreeNode* pre = nullptr;
    int currentCount = 0;
    int maxCount = 0;

    void traversal(TreeNode* node) {
        if (node == nullptr) return;

        traversal(node->left);

        // 统计当前值的频率
        if (pre != nullptr && pre->val == node->val) {
            currentCount++;
        } else {
            currentCount = 1;
        }

        // 更新众数列表  这里虽然每次都要更新一下，不会重复把一个数加进去的，不会 2222加好多
        if (currentCount == maxCount) {
            result.push_back(node->val);
        } else if (currentCount > maxCount) {   //如果一样的，每次都会变大，每次变大，那么每次都会先清空
            maxCount = currentCount;
            result.clear();
            result.push_back(node->val);
        }

        pre = node;
        traversal(node->right);
    }

public:
    vector<int> findMode(TreeNode* root) {
        result.clear();
        currentCount = 0;
        maxCount = 0;
        pre = nullptr;
        traversal(root);
        return result;
    }
};