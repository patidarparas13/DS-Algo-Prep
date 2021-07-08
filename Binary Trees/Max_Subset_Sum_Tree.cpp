//If we include some value
//inc = root->data + L.exc+R.exc

//If we exclude some value
//exc = max(L.inc,L.exc)+max(R.inc,R.exc)

//Base Case if(root==NULL) return 0;

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


class Pair{
    public:
    int inc;
    int exc;
};

Pair maxSubsetSum(Node* root){
    Pair p;
    if(root==NULL){
        p.inc=p.exc=0;
        return p;
    }

    Pair Left = maxSubsetSum(root->left);
    Pair Right = maxSubsetSum(root->right);

    p.inc = root->data + Left.exc+Right.exc;
    p.exc = max(Left.inc,Left.exc)+max(Right.inc,Right.exc);
    return p;
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
    Pair p = maxSubsetSum(root);

    cout<<"Max Subset Sum:"<<max(p.exc,p.inc)<<endl;
    bfs(root);
    return 0;
}
