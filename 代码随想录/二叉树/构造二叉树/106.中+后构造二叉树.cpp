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
    TreeNode* traversal(vector<int>& inorder,vector<int>& postorder){
        //1、空
        if(postorder.size()==0) return nullptr;
        //2.找出最后一个元素
        int val=postorder[postorder.size()-1];
        TreeNode* root =new TreeNode(val);
        if(postorder.size()==1) return root;
        //3.找出分割点
        int index;
        for(index=0;index<inorder.size();index++){
            if(inorder[index]==val) break;
        }
        //4、分割inorder
        vector<int> left_inorder(inorder.begin(),inorder.begin()+index);
        vector<int> right_inorder(inorder.begin()+index+1,inorder.end());
        //5.分割postorder
        vector<int> left_postorder(postorder.begin(),postorder.begin()+left_inorder.size());
        vector<int> right_postorder(postorder.begin()+left_inorder.size(),postorder.end()-1);
        //6.递归
        root->left=traversal(left_inorder,left_postorder);
        root->right=traversal(right_inorder,right_postorder);
        return root;
    }
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return traversal(inorder,postorder);
    }
};