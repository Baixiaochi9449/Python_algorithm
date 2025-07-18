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
 //因为是有序的，最小差值肯定是相邻的。 所以还是一个node 一个pre,遍历整个树，中序遍历！
class Solution {
private:
    int min_num=1000000;
    TreeNode* pre=nullptr;
    void traversal(TreeNode* node){
        if(node==nullptr) return ;
        traversal(node->left);
        if(pre!=nullptr){
            int cur=abs(pre->val-node->val);
            min_num=min(cur,min_num);
        }
        pre=node;
        traversal(node->right);
    }
public:
    int getMinimumDifference(TreeNode* root) {
        traversal(root);
        return min_num;
    }
};