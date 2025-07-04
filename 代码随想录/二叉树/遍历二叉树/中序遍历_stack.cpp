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
    vector<int> inorderTraversal(TreeNode* root) {
        //使用stack
        //设置一个指针  不为空，就->left, 为空就弹出并处理一个节点，然后->right
        vector<int> result;
        stack<TreeNode*> sta;
        if(root==nullptr) return result;
        TreeNode* cur=root;
        while(!sta.empty() || cur!=nullptr){  //当两个都为空的时候返回
            if(cur!=nullptr){
                sta.push(cur);
                cur=cur->left;
            }
            else{
                cur=sta.top();
                sta.pop();
                result.push_back(cur->val);
                cur=cur->right;
            }
        }
        return result;

    }
};