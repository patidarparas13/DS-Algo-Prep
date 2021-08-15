
#include <iostream>
using namespace std;

//Time Complexity: O(N/2) = O(N)

//Space Complexity: O(1)

//Info About Algo
    //We are taking the start and end pointer and swapping them

void reverse_array(int arr[],int n){
   int s = 0;
   int e = n-1;
   while(s<e){
       swap(arr[s],arr[e]);
        s+=1;
        e-=1;
   }
}


int main() {
	// your code goes here
    int arr[] = {1,6,7,43,88,300};
    int n = sizeof(arr)/sizeof(int);
    reverse_array(arr,n);
    
    for(int i=0;i<n;i++){
        cout<<arr[i]<<",";
    }
	return 0;
}

