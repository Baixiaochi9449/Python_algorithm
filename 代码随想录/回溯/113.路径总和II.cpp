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
    vector<vector<int>> result;
    vector<int> path;
    void backtracking(TreeNode* node,int targetSum,int cursum){
        if(cursum==targetSum && node->left==nullptr && node->right==nullptr){
            result.push_back(path);
            return ;
        }
        //两种选择，左走还是右走
        if(node->left!=nullptr){
            TreeNode* next=node->left;
            
                path.push_back(next->val);
                backtracking(next,targetSum,cursum+next->val);
                path.pop_back();               
            
            
        }
        if(node->right!=nullptr){
            TreeNode* next=node->right;
            
                path.push_back(next->val);
                backtracking(next,targetSum,cursum+next->val);
                path.pop_back();                
            
        }
    }
public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        if(root==nullptr) return result;

        path.push_back(root->val);
        backtracking(root,targetSum,root->val);
        return result;
    }
};