//Minimum Height BST Tree - Convert Sorted Array To BST
//We need to divide the array and find the middle element
//That will create our first node, then from
//1. s - mid-1 is our another array
//2. mid+1-e is our another array
//3. Again find middle element array , it becomes the subproblem


#include<iostream>
#include<queue>
using namespace std;

class Node{
    public:
    int key;
    Node* left;
    Node* right;
    Node(int k){
        key=k;
        left=NULL;
        right=NULL;
    }
};

Node* sortedArrayToBST(int *arr,int start,int end){
    //Return Null if s > e, because no array elements are there
    if(start>end){
        return NULL;
    }
    //Get the middle element and make it root
    int mid = (start+end)/2;
    Node* root = new Node(arr[mid]);

    //Create Left & Right Subtrees Recursively
    root->left = sortedArrayToBST(arr,start,mid-1);
    root->right = sortedArrayToBST(arr,mid+1,end);
    return root;
}

void bfs(Node* root){
    queue<Node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()){
        Node* front = q.front();
        if(front==NULL){
            q.pop();
            cout<<endl;
            if(!q.empty()){
                q.push(NULL);
            }
        }else{
            q.pop();
            cout<<front->key<<" ";
            if(front->left){
                q.push(front->left);
            }if(front->right){
                q.push(front->right);
            }
        }
    }
}

int main(){
    Node* root=NULL;
    int arr[] = {1,2,3,4,5,6,7};
    
   root =  sortedArrayToBST(arr,0,6);
   bfs(root);

}
