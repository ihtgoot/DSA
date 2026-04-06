#include<iostream>
#include<queue>
using namespace std;

class Node {
    public:
    int data;
    Node *left;
    Node *right;
    Node(int val): data(val),left(NULL),right(NULL){
    }
};

void inorder(Node *root){
    if(!root)   return;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}
void postorder(Node *root){
    if(!root)   return;
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
}
void preorder(Node *root){
    if(!root)   return;
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}

Node *CreateTree(){
    int x;
    cin>>x;
    if(x==-1)
        return NULL;
    Node *root = new Node(x);
    root->left = CreateTree();
    root->right = CreateTree();
}

int main(){
    Node * root = CreateTree();
    inorder(root);
    cout<<endl;
    postorder(root);
    cout<<endl;
    preorder(root);
}