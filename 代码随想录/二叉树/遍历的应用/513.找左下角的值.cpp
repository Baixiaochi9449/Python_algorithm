//先处理左边
//先找最深的，记录最深的值，和当前最深的叶子节点的值， 全都遍历一遍，最后返回
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
    int maxdepth=0;
    int result;
    void traversal(TreeNode* node,int depth){
        if (node==nullptr ) return ;
        depth++;  //要在最开始++
        if(node->left==nullptr && node->right==nullptr){
            if(depth>maxdepth) {
                result=node->val;
                maxdepth=depth;
            }
        }
        if(node->left!=nullptr) traversal(node->left,depth);
        if(node->right!=nullptr) traversal(node->right,depth);
        return ;
    }
public:
    int findBottomLeftValue(TreeNode* root) {
        traversal(root,0);
        return result;
    }
};