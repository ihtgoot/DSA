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

int main(){
    int x;
    cin>>x;
    queue<Node*>q;
    Node *root = new Node(x);
    q.push(root);
    while(!q.empty()){
        Node *top = q.front();
        q.pop();
        int l,r;
        cin>>l;
        if(l!=-1){
            top->left = new Node(l);
            q.push(top->left);
        }
        cin>>r;
        if(r!=-1){
            top->right = new Node(r);
            q.push(top->right);
        }
    }

    inorder(root);
    cout<<endl;
    postorder(root);
    cout<<endl;
    preorder(root);
}