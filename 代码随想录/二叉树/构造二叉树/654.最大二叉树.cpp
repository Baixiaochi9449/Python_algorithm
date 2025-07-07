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
    TreeNode* traversal(vector<int>& nums){
        //数组为空，返回空节点
        if(nums.size()==0) return nullptr;
        //数组不为空，找到数组中的最大值
        int index=0;
        int maxval=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]>maxval){
                maxval=nums[i];
                index=i;
            }
        }
        TreeNode* root=new TreeNode(maxval);
        if(nums.size()==1) return root;

        //找到左区间
        vector<int> leftnums(nums.begin(),nums.begin()+index);
        vector<int> rightnums(nums.begin()+index+1,nums.end());
        //递归
        root->left=traversal(leftnums);
        root->right=traversal(rightnums);
        return root;
    }
public:
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return traversal(nums);
    }
};