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
 //不同的是，这道题返回的是字符串，深搜，前序遍历
class Solution {
private:
    vector<string> result;
    string path="";
    void traversal(TreeNode* node){
        if(node==nullptr) return ;
        if(node->left==nullptr && node->right==nullptr){ //叶子节点，收集路径
            result.push_back(path);
            return ;
        }
        if(node->left!=nullptr){
            string ch=to_string(node->left->val);
            string temp="->"+ch;
            path+=temp;
            traversal(node->left);
            path.erase(path.end()-temp.size(),path.end());
        }
        if(node->right!=nullptr){
            string ch=to_string(node->right->val);
            string temp="->"+ch;
            path+=temp;
            traversal(node->right);
            path.erase(path.end()-temp.size(),path.end());
        }
        return ;
    }
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        result.clear();
        path="";
        path+=to_string(root->val);
        traversal(root);
        return result;
    }
};