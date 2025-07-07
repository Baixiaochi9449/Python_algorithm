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
    bool find(TreeNode* node,int targetSum,int cursum){
        //回溯，每层有两种情况
        if(node==nullptr) return false;

        cursum+=node->val;
        if(cursum==targetSum && node->left==nullptr && node->right==nullptr){
            return true;
        }
        if(node->left!=nullptr){
            if(find(node->left,targetSum,cursum)){
                return true;
            }
        }
        if(node->right!=nullptr){
            if(find(node->right,targetSum,cursum)){
                return true;
            }
        }
        return false;
    }
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        return find(root,targetSum,0);
    }
};