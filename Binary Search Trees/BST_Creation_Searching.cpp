#include<iostream>
using namespace std;

class Node{
     public:
     int key;
          Node *left;
     Node *right;
     Node(int k){
          key=k;
          left=NULL;
          right=NULL;
     }
};
Node* insert(Node *root,int key){
    if(root==NULL){
        return new Node(key);
    }
    if(key<root->key){
        root->left=insert(root->left,key);
    }else{
        root->right=insert(root->right,key);
    }
    return root;
}
bool search(Node *root,int key){
    if(root==NULL){
        return false;
    }
    if(key==root->key){
        return root;
    }
    if(key<root->key){
    search(root->left,key);

    }else{
    search(root->right,key);

    }
}

void print_tree(Node *root){
    if(root==NULL){
        return;
    }
    print_tree(root->left);
    cout<<root->key<<" ";
    print_tree(root->right);
}
int main(){
    Node *root=NULL;
    int arr[] = {10, 5, 1, 7, 40, 50};
    for(auto i:arr){
        root = insert(root,i);
    }
    print_tree(root);
    cout<<endl;
    cout<<search(root,10);

    return 0;
}