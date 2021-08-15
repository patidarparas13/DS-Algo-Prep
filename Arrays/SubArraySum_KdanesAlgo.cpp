
#include <iostream>
#include<climits>
using namespace std;

//Problem Statement: Print the sum of each subarray and find out the largest sum
//Time Complexity: = O(N)

//Space Complexity: O(1)

//Info About Algo
    //Kdane's Alg0

int subArraySumKdanesAlgo(int arr[],int n){
   int current = 0;
   int max_so_far = 0;
   for(int i=0;i<n;i++){
       current =current +arr[i];
       if(current<0){
           current = 0;
       }
         max_so_far = max(max_so_far,current);
   }
    cout<<endl;
    return max_so_far;
}  


int main() {
	// your code goes here
    int arr[] = {-2,3,4,-1,5,-12,6,1,3};
    int n = sizeof(arr)/sizeof(int);
    int sum = subArraySumKdanesAlgo(arr,n);
    cout<<"Max Sum:"<<sum;
	return 0;
}

