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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        //正常从上到下存储每一层的，再翻转数组
        vector<vector<int>> result;
        queue<TreeNode*> que;
        if(root==nullptr) return result;
        que.push(root);
        while(!que.empty()){
            int size=que.size();
            vector<int> vec;
            while(size--){
                TreeNode* cur=que.front();
                que.pop();
                vec.push_back(cur->val);
                if(cur->left!=nullptr) que.push(cur->left);
                if(cur->right!=nullptr) que.push(cur->right);
            }
            result.push_back(vec);
        }
        reverse(result.begin(),result.end());
        return result;
    }
};