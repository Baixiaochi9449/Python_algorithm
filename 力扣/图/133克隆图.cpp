/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/
//意思是： 然后我需要把他们都存储到Node里面？
class Solution {
private:
    unordered_map<Node*,Node*> visit;
    Node* dfs(Node* node){
        if(node==nullptr) return node;
        if(visit.count(node))return visit[node];

       
        Node* newnode=new Node(node->val);
        visit[node]=newnode;    //原始node->对于newnode   他们的引用不一样，是两个不同的图。 visit是用来返回的，所以必须新的node
        for(Node* neighbor : node->neighbors){
            newnode->neighbors.push_back(dfs(neighbor));
        }
        return newnode;
    }
public:
    Node* cloneGraph(Node* node) {
        return dfs(node);
    }
};