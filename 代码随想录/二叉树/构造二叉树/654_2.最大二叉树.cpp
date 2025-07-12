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
 //递归。 先找数组里的最大数-》根节点。  然后找左区间和右区间。 然后左右子树递归
class Solution {
private:
    TreeNode* construct(vector<int>& nums){
        if(nums.size()==0) return nullptr;
        
        int maxval=0;
        int index;
        for(int i=0;i<nums.size();i++){
            if(nums[i]>maxval){
                maxval=nums[i];
                index=i;
            }
        }
        
        TreeNode* root = new TreeNode(maxval);
        if(nums.size()==1) return root;

        vector<int> leftnum(nums.begin(),nums.begin()+index);
        vector<int> rightnum(nums.begin()+index+1,nums.end());

        root->left=construct(leftnum);
        root->right=construct(rightnum);
        return root;
    }
public:
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return construct(nums);
    }
};