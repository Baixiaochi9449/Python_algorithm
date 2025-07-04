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
    int getdepth(TreeNode* node){
        if(node==nullptr) return 0;
        int minDepth;
        if(node->left==nullptr && node->right!=nullptr){
            return 1+getdepth(node->right);
        }
        if(node->right==nullptr && node->left!=nullptr){
            return 1+getdepth(node->left);
        }
        int left=getdepth(node->left);
        int right=getdepth(node->right);
        minDepth=1+min(left,right);
        return minDepth;
    }
public:
    int minDepth(TreeNode* root) {
        return getdepth(root);
    }
};