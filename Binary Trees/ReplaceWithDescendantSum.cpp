//Given a binary tree, replace every node by sum of all its descedants, leave leaf nodes intact ?

//Hint: We need to keep the data of parent node intact while replacing with node with descedant sum
//int temp = root->data
//root->data = LS + RS 
//return temp+root->data;

//PostOrder: L+R+Root
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

int replaceWithSum(Node* root){
    //Base Case
    if(root==NULL){
        return 0;
    }
    //We do not want to replace the value of leaf node
    if(root->left==NULL && root->right==NULL){
        return root->data;
    }

    //Recursive Case
    int LS = replaceWithSum(root->left);
    int RS = replaceWithSum(root->right);

    int temp = root->data;
    root->data = LS+RS;
    return root->data+temp;
    
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
    cout<<"Root Node Sum:"<<replaceWithSum(root)<<endl;
    bfs(root);
    return 0;
}
