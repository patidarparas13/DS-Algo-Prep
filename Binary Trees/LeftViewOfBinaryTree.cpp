#include<bits/stdc++.h>
using namespace std;

class Node
{
  public:
   int key;
   Node *left;
   Node *right;

   Node(int key){
       this->key = key;
       left = right  = NULL;
   }
};

void traverseTree(Node* root,vector<int> &leftView){
    queue<Node*> q;
    q.push(root);
    q.push(NULL);
    Node* prev=NULL;
    while(!q.empty()){
        Node* front = q.front();
        if(front==NULL){
            q.pop();
            prev=NULL;

            cout<<endl;
            if(!q.empty()){
                q.push(NULL);
            }
        }else{
            if(prev==NULL){
                leftView.push_back(front->key);
                prev = front;
            }
            
            q.pop();
            if(front->left){
                q.push(front->left);
            }if(front->right){
                q.push(front->right);
            }
        }
    }
    return;
}
vector<int> leftView(Node * root){
    //Complete the function
    vector<int> leftView;
    traverseTree(root,leftView);
    return leftView;
    
    
    
}