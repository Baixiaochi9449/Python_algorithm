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
        int left=getdepth(node->left);
        int right=getdepth(node->right);
        int maxDepth=1+max(left,right);
        return maxDepth;
    }
public:
    int maxDepth(TreeNode* root) {
        return getdepth(root);
    }
};
