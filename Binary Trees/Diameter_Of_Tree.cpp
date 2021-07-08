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

int height(Node* root){
    if(root==NULL){
        return 0; 
    }
    int h1 = height(root->left);
    int h2 = height(root->right);
    return max(h1,h2)+1;
}

//Time Complexity: O(N^2)
int diameter(Node* root){
    if(root==NULL){
        return 0;
    }
    int d1 = height(root->left)+height(root->right);
    int d2 = diameter(root->left);
    int d3 = diameter(root->right);
    return max(d1,max(d2,d3));

}
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
    bfs(root);
    cout<<endl;
    cout<<"Diameter is:"<<diameter(root)<<endl;
    return 0;
}