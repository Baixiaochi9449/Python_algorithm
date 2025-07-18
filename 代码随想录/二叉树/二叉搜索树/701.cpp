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
 //二叉搜索树，就迭代法，与当前节点比较，如果大，就往右走，如果小就左，如果找到叶子节点，就插入。
 //往左/右边走，空了就插入。
class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        TreeNode* newnode = new TreeNode(val);
        if(root==nullptr){
            return newnode;
        }
        TreeNode* node = root;
        while(node!=nullptr){
            if(node->val>val){
                if(node->left==nullptr){
                    node->left=newnode;
                    break;
                }
                node=node->left;
            }
            if(node->val<val){
                if(node->right==nullptr){
                    node->right=newnode;
                    break;
                }
                node=node->right;
            }
        }
        return root;
    }
};