/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
 //因为是有序的，最小差值肯定是相邻的。 所以还是一个node 一个pre,遍历整个树，中序遍历！
class Solution {
private:
    TreeNode* pre=nullptr;
    int mininum=10000000;
    void traversal(TreeNode* node){
        if(node==nullptr) return ;
        traversal(node->left);
        if(pre!=nullptr){
            int cur=abs(node->val-pre->val);
            if(cur<mininum) mininum=cur;
        }
        pre=node;// 中序遍历，所有的处理必须在中间
        traversal(node->right);
        return ;
    }
public:
    int getMinimumDifference(TreeNode* root) {
        traversal(root);
        return mininum;
    }
};