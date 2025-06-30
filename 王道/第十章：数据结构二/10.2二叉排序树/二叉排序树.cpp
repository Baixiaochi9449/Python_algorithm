#include <iostream>

using namespace std;

struct Node{
    int data;
    Node* leftchild;
    Node* rightchild;
    Node(int data):data(data),leftchild(NULL),rightchild(NULL){};
};

Node* insert(Node* root,int data,int father){
    if(root==NULL){     //每次插入都是执行的这个，靠root=NULL插入的
        root = new Node(data);     
        cout << father << endl;
    }
    else if(root->data>data){
        root->leftchild=insert(root->leftchild,data,root->data);
    }
    else{
        root->rightchild=insert(root->rightchild,data,root->data);
    }
    return root;
}

int main(){
    int n;
    while(cin >> n){
        Node* root=NULL;
        for(int i=0;i<n;i++){
            int data;
            cin >> data;
            root=insert(root,data,-1);
        }
    }
    return 0;
}