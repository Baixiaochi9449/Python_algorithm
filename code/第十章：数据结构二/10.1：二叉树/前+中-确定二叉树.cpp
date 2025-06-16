#include <iostream>
#include <string>
using namespace std;

struct Node{
    char data;
    Node* leftchild;
    Node* rightchild;
    Node(char c):data(c),leftchild(NULL),rightchild(NULL){};
};

Node* Bulid(string str1,string str2){
    if(str1.size()==0){
        return NULL;
    }
    char c =str1[0];     //靠前序来判断根节点是谁
    Node* root=new Node(c);  //对节点的处理
    int position =str2.find(c);

    root->leftchild=Bulid(str1.substr(1,position),str2.substr(0,position));
    root->rightchild=Bulid(str1.substr(position+1),str2.substr(position+1));
    return root;
}

void postorder(Node* root){
    if(root==NULL){
        return ;
    }
    postorder(root->leftchild);
    postorder(root->rightchild);
    cout << root->data;
    return ;
}

int main(){
    string str1,str2;
    while(cin >> str1 >> str2){
        Node* root=Bulid(str1,str2);
        postorder(root);
        cout << endl;
    }
    return 0;
}
