
#include <iostream>
using namespace std;

//Time Complexity
    //Worst Case: O(log n)
    //Average Case: O(log n)
    //Best Case: O(1)

//Space Complexity: O(1)

//Fast & Efficient : If Array Should Be Sorted
//Search space should be monotonic: Either non-decreasing or non-increasing

int binary_search(int arr[],int n,int key){
    int s=0;
    int e = n-1;
    while(s<=e){
        int mid = (s+e)/2;
        if(arr[mid]==key){
            return mid;
        }else if(arr[mid]>key){
            e = mid-1;
        }else{
            s = mid+1;
        }
    }
    return -1;
}


int main() {
	// your code goes here
    int arr[] = {1,6,7,43,88,300};
    int n = sizeof(arr)/sizeof(int);
    int key;
    cin>>key;
    int index = binary_search(arr,n,key);
    if(index!=-1){
        cout<<key<<" is found at index "<<index<<endl;
    }else{
        cout<<key<<" is not found!"<<endl;

    }
	return 0;
}

