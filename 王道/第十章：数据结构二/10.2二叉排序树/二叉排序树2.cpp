#include <iostream>

using namespace std;

struct Node{
    int data;
    Node* leftchild;
    Node* rightchild;
    Node(int data):data(data),leftchild(NULL),rightchild(NULL){};
};

Node* insert(Node* root,int data){
    if(root==NULL){
        root=new Node(data);
    }
    else if(data<root->data){
        root->leftchild=insert(root->leftchild,data);
    }
    else if(data>root->data){
        root->rightchild=insert(root->rightchild,data);
    }
    return root;
}

void Preorder(Node* root){
    if(root==NULL){
        return ;
    }
    cout << root->data << ' ';
    Preorder(root->leftchild);
    Preorder(root->rightchild);
    return ;
}

void Inorder(Node* root){
    if(root==NULL){
        return ;
    }
    Inorder(root->leftchild);
    cout << root->data << ' ';
    Inorder(root->rightchild);
    return ;
}

void Postorder(Node* root){
    if(root==NULL){
        return ;
    }
    Postorder(root->leftchild);
    Postorder(root->rightchild);
    cout << root->data << ' ';
    return ;
}


int main(){
    int n;
    while(cin >>n){
        Node* root=NULL;
        for(int i=0;i<n;i++){
            int data;
            cin >> data;
            root=insert(root,data);
        }
        Preorder(root);
        cout << endl;
        Inorder(root);
        cout <<endl;
        Postorder(root);
        cout << endl;
    }
    return 0;
}