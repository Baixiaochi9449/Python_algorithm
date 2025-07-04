/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
private:
    int getdepth(Node* node){
        if(node==nullptr) return 0;
        int maxdepth=0;
        for(int i=0;i<node->children.size();i++){
            int curdepth=getdepth(node->children[i]);
            if(curdepth>maxdepth){
                maxdepth=curdepth;
            }
        }
        int depth=1+maxdepth;
        return depth;
    }
public:
    int maxDepth(Node* root) {
        int result;
        result = getdepth(root);
        return result;
    }
};