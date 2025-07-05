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
    vector<vector<vector<TreeNode*>>> memo;
    vector<TreeNode*> generateTrees(int n) {
        if (n == 0) return vector<TreeNode*>{};
        memo.resize(n+1,vector<vector<TreeNode*>>(n+1,vector<TreeNode*>()));
        return count(1,n);
    }
    vector<TreeNode*> count(int lo,int hi){
        vector<TreeNode*> res;
        if(lo>hi){
            res.emplace_back(nullptr);
            return res;
        }
        
        if (!memo[lo][hi].empty()) {
            return memo[lo][hi];
        }

        for(int i=lo;i<=hi;i++){
            vector<TreeNode*> leftTree = count(lo, i - 1);
            vector<TreeNode*> rightTree = count(i + 1, hi);
            for (auto left : leftTree) {
                for (auto right : rightTree) {
                    // i 作为根节点 root 的值
                    TreeNode* root = new TreeNode(i);
                    root->left = left;
                    root->right = right;
                    res.emplace_back(root);
                }
            }
        }
        memo[lo][hi]=res;
        return res;
    }
};