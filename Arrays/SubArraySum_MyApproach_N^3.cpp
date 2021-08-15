
#include <iostream>
#include<climits>
using namespace std;

//Problem Statement: Print the sum of each subarray and find out the largest sum
//Time Complexity: = O(N^3)

//Space Complexity: O(1)

//Info About Algo
    //We are iterating through i to j using k as an elements, 
    //For generating all subarray and storing it in a local sum
    //And compairing it with the largest sum so far

void printSubArrays(int arr[],int n){
    int largest = INT_MIN;
    int start_idx=-1;
    int end_idx=-1;
   for(int i=0;i<n;i++){
       for(int j=i;j<n;j++){
           int sum = 0;
           for(int k=i;k<=j;k++){
               sum+= arr[k];
            //   cout<<arr[k]<<",";
           }
        //    cout<<"--->"<<sum<<endl;
           if(sum>largest){
               start_idx = i;
               end_idx = j;
               largest = sum;
           }
       }
   }
   cout<<"-------------------------------"<<endl;
   for(int i=start_idx;i<=end_idx;i++){
       cout<<arr[i]<<",";
   }
   cout<<endl;
}


int main() {
	// your code goes here
    int arr[] = {-1,20,-40,9,0,-10};
    int n = sizeof(arr)/sizeof(int);
    printSubArrays(arr,n);
	return 0;
}

