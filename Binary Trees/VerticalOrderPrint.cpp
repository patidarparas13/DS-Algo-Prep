#include <iostream>
#include <queue>
#include <map>
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
Node *buildLevelOrderTree()
{
    int d;
    cin >> d;
    Node *root = new Node(d);
    queue<Node *> q;
    q.push(root);

    while (!q.empty())
    {
        Node *current = q.front();
        q.pop();
        int c1, c2;
        cin >> c1 >> c2;
        if (c1 != -1)
        {
            current->left = new Node(c1);
            q.push(current->left);
        }
        if (c2 != -1)
        {
            current->right = new Node(c2);
            q.push(current->right);
        }
    }
    return root;
}

void traverse(Node *root, int d, map<int, vector<int>> &m)
{
    if (root == NULL)
    {
        return;
    }
    m[d].push_back(root->data);
    traverse(root->left, d - 1, m);
    traverse(root->right, d + 1, m);
    return;
}

void verticalOrderPrint(Node *root)
{
    map<int, vector<int>> m;
    int d = 0;
    traverse(root, d, m);

    for (auto p : m)
    {
        int key = p.first;
        vector<int> line = p.second;
        for (auto data : line)
        {
            cout << data << " ";
        }
        cout << endl;
    }
    return;
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
    verticalOrderPrint(root);
    bfs(root);
    return 0;
}