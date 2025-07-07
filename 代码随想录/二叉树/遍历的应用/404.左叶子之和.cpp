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
 //如何判断是左叶子：只能从父节点判断
 //判断条件： node->left!=null && node->left->left==null,node->left->right==null
 //最后的值：左子树的左叶子之和+ 右子树的左叶子之和
class Solution {
private: 
    int traversal(TreeNode* root){
        if(root==nullptr) return 0;
        if(root->left==nullptr && root->right==nullptr) return 0;
        
        int result,leftsum,rightsum;
        leftsum=traversal(root->left);
        if(root->left!=nullptr && root->left->left==nullptr && root->left->right==nullptr){
            leftsum=root->left->val;
        }
        rightsum=traversal(root->right);

        result=leftsum+rightsum;
        return result;
    }
public:
    int sumOfLeftLeaves(TreeNode* root) {
        return traversal(root);
    }
};