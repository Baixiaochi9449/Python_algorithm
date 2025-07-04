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
public: 
    vector<int> preorderTraversal(TreeNode* root) {
       //stack 
       stack<TreeNode*> sta;
       vector<int> result;
       if(root==nullptr) return result;

       sta.push(root);
       while(!sta.empty()){
        TreeNode* cur=sta.top();
        sta.pop();
        result.push_back(cur->val);
        if(cur->right!=nullptr) sta.push(cur->right);
        if(cur->left!=nullptr) sta.push(cur->left);
       }
       return result;
    }
};