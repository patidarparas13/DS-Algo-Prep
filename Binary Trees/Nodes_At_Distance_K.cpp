//Given a Binary Tree and a target Node T.
//  Find all the Nodes at distance K from given Node, where K is also an integer input.

#include <iostream>
#include <queue>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;
    Node(int d)
    {
        data = d;
        left = NULL;
        right = NULL;
    }
};
Node* buildLevelOrderTree(){
    int d;
    cin>>d;
    Node* root = new Node(d);
    queue<Node*> q;
    q.push(root);

    while(!q.empty()){
        Node* current = q.front();
        q.pop();
        int c1,c2;
        cin>>c1>>c2;
        if(c1!=-1){
            current->left = new Node(c1);
            q.push(current->left);
        }if(c2!=-1){
            current->right = new Node(c2);
            q.push(current->right);
        }
    }
return root;
}

void printAtLevelK(Node* root,int k){
    if(root==NULL){
        return;
    }
    if(k==0){
        cout<<root->data<<" ";
        return;
    }
    printAtLevelK(root->left,k-1);
    printAtLevelK(root->right,k-1);
    return;

}
int printNodesAtDistanceK(Node* root,Node* target,int k){
    //base case
    if(root==NULL){
        return -1;
    }

    //Reach the target Node
    if(root==target){
        printAtLevelK(target,k);
        return 0;
    }
    //Other Case
    int DL = printNodesAtDistanceK(root->left,target,k);
    if(DL!=-1){
        //2 Cases
        //Print the current Node
        if(DL+1==k){
            cout<<root->data;
        }
        //Or Print some nodes in the right subtree
        else{
            printAtLevelK(root->right,k-2-DL);
        }
        return 1+DL;
    }
    int DR = printNodesAtDistanceK(root->right,target,k);
    if(DR!=-1){
        //2 Cases
        //Print current Node
        if(DR+1==k){
            cout<<root->data<<" ";
        }else{
            printAtLevelK(root->left,k-2-DR);
        }
        return 1+DR;
    }
    return -1;
}
void bfs(Node *root)
{
    queue<Node *> q;
    q.push(root);
    q.push(NULL);
    while (!q.empty())
    {
        Node *front = q.front();
        if (front == NULL)
        {
            cout << endl;
            q.pop();
            if (!q.empty())
            {
                q.push(NULL);
            }
        }
        else
        {
            q.pop();

            cout << front->data << ",";

            if (front->left)
            {
                q.push(front->left);
            }
            if (front->right)
            {
                q.push(front->right);
            }
        }
    }
}
int main()
{
    Node *root = buildLevelOrderTree();
    //Node* target = new Node(5);
    printNodesAtDistanceK(root,target,1);
    bfs(root);
    return 0;
}
