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
    TreeNode* traversal(vector<int>& preorder, vector<int>& inorder) {
        //如果为空数组
        if(preorder.size()==0) return nullptr;
        //找到根节点的值
        int val=preorder[0];
        TreeNode* root=new TreeNode(val);
        if(preorder.size()==1) return root;
        //找切割位置
        int i;
        for(i=0;i<inorder.size();i++){
            if(inorder[i]==val) break;
        }
        //找中序的左右区间
        vector<int> left_in(inorder.begin(),inorder.begin()+i);
        vector<int> right_in(inorder.begin()+i+1,inorder.end());
        //找前序的左右区间(根据中序的长度找)
        vector<int> left_pre(preorder.begin()+1,preorder.begin()+left_in.size()+1);
        vector<int> right_pre(preorder.begin()+left_in.size()+1,preorder.end());
        //递归
        root->left=traversal(left_pre,left_in);
        root->right=traversal(right_pre,right_in);
        
        return root;

    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return traversal(preorder,inorder);
    }
};