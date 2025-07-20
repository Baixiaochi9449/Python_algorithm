/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 //搜左子树，搜右子树，如果找到了，就返回当前节点
class Solution {
private:
    TreeNode* traversal(TreeNode* node,TreeNode* p,TreeNode* q){
        if(node==p) return p;
        if(node==q) return q;
        if(node==nullptr) return node;

        TreeNode* left = traversal(node->left,p,q);
        TreeNode* right = traversal(node->right,p,q);
        if(left!=nullptr && right!=nullptr) return node;
        if(left!=nullptr && right==nullptr) return left;
        if(left==nullptr && right!=nullptr) return right;
        if(left==nullptr && right==nullptr) return nullptr;
        return nullptr;
    }
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return traversal(root,p,q);
    }
};