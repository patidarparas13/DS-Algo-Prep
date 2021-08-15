
#include <iostream>
using namespace std;

//Worst Case: O(n)
//Average Case: O(log n)
//Best Case: O(1)
int linear_search(int arr[],int n,int key){
    for(int i=0;i<n;i++){
        if(arr[i]==key){
            return i;
        }
    }
    return -1;
}

int main() {
	// your code goes here
    int arr[] = {1,6,7,43,8,3};
    int n = sizeof(arr)/sizeof(int);
    int key;
    cin>>key;
    int index = linear_search(arr,n,key);
    if(index!=-1){
        cout<<key<<" is found at index "<<index<<endl;
    }else{
        cout<<key<<" is not found!"<<endl;

    }
	return 0;
}

