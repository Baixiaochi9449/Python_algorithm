#include <iostream>
#include <string>
using namespace std;

struct Node{
    char data;
    Node* leftchild;
    Node* rightchild;
    Node(char c):data(c),leftchild(NULL),rightchild(NULL) {} ;
};

Node* Bulid(int& position,string str){  //position要按照引用来传递，每次递归修改了position都要改
    char c=str[position];
    position++;
    if(c=='#'){
        return NULL;
    }
    Node* root =new Node(c);    //处理节点
    root->leftchild=Bulid(position,str);
    root->rightchild=Bulid(position,str);
    return root;
}

void Inorder(Node* root){
    if(root==NULL){
        return ;
    }
    Inorder(root->leftchild);
    cout << root->data << ' ';    //处理节点
    Inorder(root->rightchild);
    return ;
}

int main(){
    string str;
    while(cin >> str){
        int position =0; //引用传递，所以在最初必须有一个变量空间
        Node* root=Bulid(position,str);
        Inorder(root);
        cout << endl;
    }
}