public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        TreeNode* newnode=new TreeNode(val);
        TreeNode* node=root;
        if(root==nullptr) return newnode;
        while(root!=nullptr){
            if(val>root->val){
                if(root->right==nullptr) {
                    root->right=newnode;
                    return node;
                }
                else{
                    root=root->right;
                }
            }
            if(val<root->val){
                if(root->left==nullptr) {
                    root->left=newnode;
                    return node;
                }
                else root=root->left;
            }
        }
        return node;
    }
};