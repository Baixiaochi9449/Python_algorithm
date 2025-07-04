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
class Solution {
private:
    TreeNode* invert(TreeNode* node){
        if(node==nullptr) return node;
        swap(node->left,node->right);
        invert(node->left);   //没有处理返回值，反正每次迭代都翻转了
        invert(node->right);
        return node;   //每一层都有返回，在最初的层 返回了最终的值
    } 
public:
    TreeNode* invertTree(TreeNode* root) {
        return invert(root);
    }
};