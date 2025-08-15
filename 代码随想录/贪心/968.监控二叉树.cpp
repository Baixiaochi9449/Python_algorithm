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
        int result=0;
        int traversal(TreeNode* cur){
            if(cur==nullptr) return 2; //空节点，返回有覆盖的状态
            //后序，左中右
            int left=traversal(cur->left);
            int right=traversal(cur->right);
            if(left==2 && right==2) return 0;
            if(left==0 || right==0){
                result++;
                return 1;
            }
            if(left==1 || right==1) return 2;
            //3个if已经覆盖了所有的情况了
            return -1;
        }
    public:
        int minCameraCover(TreeNode* root) {
            result=0;
            if(traversal(root)==0) result++;
            return result;
        }
    };