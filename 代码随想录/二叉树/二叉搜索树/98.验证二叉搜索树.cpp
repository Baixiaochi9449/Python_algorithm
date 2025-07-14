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
 //不能只比较 node->val < node->right->val  和node->val>node->left->val  因为要保证所有的左子树要小于跟，所有的右子树的节点大于中间节点
 //搜索树是有顺序的。 中序遍历就是它的顺序。  就相当于中序遍历，一个pre,一个node ,依次遍历
class Solution {
private:
    TreeNode* pre=nullptr;
    bool traversal(TreeNode* node){
        if(node==nullptr) return true;

        if (!traversal(node->left)) {
            return false;
        }
        
        if(pre!=nullptr && pre->val>=node->val) return false;
        pre=node;

        if(!traversal(node->right)){
            return false;
        }
        return true;
    }
public:
    bool isValidBST(TreeNode* root) {
        return traversal(root);
    }
};