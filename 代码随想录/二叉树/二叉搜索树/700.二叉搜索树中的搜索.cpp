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
 //比较当前节点： 相等返回， 大于 递归右子树，小于 递归左子树
class Solution {
private:
    TreeNode* search(TreeNode* node,int val){
        if(node==nullptr) return nullptr;
        if(node->val==val) return node;
        if(node->val>val){
            return search(node->left,val);
        }
        if(node->val<val){
            return search(node->right,val);
        }
        return nullptr;
    }
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        return search(root,val);
    }
};