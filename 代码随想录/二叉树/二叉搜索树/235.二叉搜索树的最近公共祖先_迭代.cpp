/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
//二叉搜索树，也可以用普通二叉树那样找
//有顺序，返回先搜索到的那个，如果分叉了，就返回分叉点
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        while(root){
            if(root->val>p->val && root->val<q->val) return root;
            if(root->val>q->val && root->val<p->val) return root;
            if(root->val==p->val) return p;
            if(root->val==q->val) return q;
            if(root->val>q->val && root->val>p->val) root=root->left;
            if(root->val<q->val && root->val<p->val) root=root->right;
        }
        return nullptr;
    }
};