// Given a binary tree, check if it is a height balanced tree
//A non-empty binary tree T is balanced if:
//1) Left Subtree Of T is balanced
//2) Right Subtree of T is balanced
//3) The difference between heights of left subtree and right subtree is not more than 1
// |h1-h2|<=1

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

//O(N) Time
pair<int,bool> isHeightBalanced(Node* root){
    pair<int,bool> p, Left,Right;

    //Base Case
    if(root==NULL){
        p.first = 0; //Height
        p.second = true; //Balanced
        return p;
    }

    //Recursive Case
    //Post Order Traversal
    Left = isHeightBalanced(root->left);
    Right = isHeightBalanced(root->right);

    int height = max(Left.first,Right.first)+1;

    if(abs(Left.first-Right.first)<=1 and Left.second and Right.second){
        return make_pair(height,true);
    }
    return make_pair(height,false);
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
    pair<int,bool> p = isHeightBalanced(root);
    if(p.second){
    cout<<"Tree Is Balanced!"<<endl;

    }else{
    cout<<"Tree Is Not Balanced!"<<endl;

    }
    bfs(root);
    return 0;
}
