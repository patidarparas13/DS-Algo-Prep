
#include <iostream>
#include<climits>
using namespace std;

//Problem Statement: Print the sum of each subarray and find out the largest sum
//Time Complexity: = O(N^2)

//Space Complexity: O(1)

//Info About Algo
    //We are generating the prefix sum array
    //And then we will find the sum by using the formula
    //i>0 ?prefix_sum[j] - prefix_sum[i-1]:prefix_sum[j]


int prefix_sum(int arr[],int n){
    int prefix_sum[n]={0};
    prefix_sum[0] = arr[0];

    //O(N)
    for(int i=1;i<n;i++){
        prefix_sum[i] = prefix_sum[i-1] + arr[i];
    }

    //Largest Sum Logic
    int largest_sum =0;
    //O(N^2)
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            //If i is less than zero then prefix sum will be prefix[j] 
            //because it calculated till 0 to prefix[j];
            //Else you can do prefix_sum[i-1]:prefix_sum[j]
            int subarray_sum = i>0 ?prefix_sum[j] - prefix_sum[i-1]:prefix_sum[j];
            largest_sum  = max(subarray_sum,largest_sum);
        }
    }
    return largest_sum;
}


int main() {
	// your code goes here
    int arr[] = {-2,3,4,-1,5,-12,6,1,3};
    int n = sizeof(arr)/sizeof(int);
    int sum = prefix_sum(arr,n);
    cout<<"Max Sum:"<<sum;
	return 0;
}

