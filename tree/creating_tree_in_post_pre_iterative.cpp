#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>
using namespace std;

class Node {
    public:
    int data;
    Node *left;
    Node *right;
    Node(int val): data(val),left(NULL),right(NULL){
    }
};

vector<int> inorder(Node *root){
    vector<int>ans;
    stack<Node *>stk;
    stk.push(root);
    
    
    
    return ans;

}
vector<int> postorder(Node *root){
    vector<int>ans;
    stack<Node *>stk;
    stk.push(root);
    while(!stk.empty()){
        Node *temp = stk.top();
        stk.pop();
        if(temp->left)  stk.push(temp->left);
        if(temp->right)  stk.push(temp->right);
        ans.push_back(temp->data);
    }
    reverse(ans.begin(),ans.end());
    return ans;
}
vector<int> preorder(Node *root){
    vector<int>ans;
    stack<Node *>stk;
    stk.push(root);
    while(!stk.empty()){
        Node *temp = stk.top();
        stk.pop();
        if(temp->right)  stk.push(temp->right);
        ans.push_back(temp->data);
        if(temp->left)  stk.push(temp->left);
    }
    return ans;
}

Node *CreateTree(){
    int x;
    cin>>x;
    if(x==-1)
        return NULL;
    Node *root = new Node(x);
    root->left = CreateTree();
    root->right = CreateTree();
    return root;
}

int main(){
    Node * root = CreateTree();
    vector<int>in = inorder(root);
    vector<int>post = postorder(root);
    vector<int>pre = preorder(root);
    for(int i=0;i<in.size();i++){
        cout<<pre[i]<<" ";
    }
    cout<<endl;
    for(int i=0;i<in.size();i++){
        cout<<post[i]<<" ";
    }
    // cout<<endl;
    // for(int i=0;i<in.size();i++){
    //     cout<<pre[i]<<" ";
    // }
    cout<<endl;
}