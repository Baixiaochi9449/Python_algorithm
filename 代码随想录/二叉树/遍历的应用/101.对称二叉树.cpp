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
 //左节点的左孩子，右节点的有孩子.  后序遍历
class Solution {
private:
    bool isSame(TreeNode* left,TreeNode* right){
        if(left==nullptr && right!=nullptr) return false;
        if(left!=nullptr && right==nullptr) return false;
        if(left==nullptr && right==nullptr) return true;
        if(left->val!=right->val) return false;
        bool leftresult=isSame(left->left,right->right);
        bool rightresult=isSame(left->right,right->left);
        if(leftresult && rightresult) return true;
        else return false;
    }
public:
    bool isSymmetric(TreeNode* root) {
        return isSame(root->left,root->right);
    }
};