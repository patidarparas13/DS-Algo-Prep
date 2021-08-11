#include<iostream>
using namespace std;

//Along one side of a road is a sequence of vacant plots of land.
//Each plot has a different area(non-zero). So, the areas form a sequence
//A[1],A[2],...A[N].

//You want to buy K acres of land to build a house. You want to find
//all segments of continguous plots(i.e., a subsection in the sequence)
//of whose sum is exactly k.

//Sample Input
//Plots = {1,3,2,1,4,1,3,2,1,1,2}
//k=8

//Sample Output
//2 5
//4 6
//5 9

void housing(int *arr,int n,int k){
    int i=0;
    int j=0;
    int cs=0;
    while(j<n){
        //Expand to right
        cs += arr[j];
        j++;
        
        //Remove elements from the left till CS>sum and i<j
        while(cs>k and i<j){
            cs = cs -arr[i];
            i++;
        }

        //Check if at any given point 
        if(cs==k){
            //Print that window
            cout<<i<<" - "<<j-1<<endl;
        }
    }
    return;
}

int main(){

    //Smallest window that contains the required sum
    //Handle if you have negative integers in the arrays
    int plots[] = {1,3,2,1,4,1,3,2,1,1};
    int n = sizeof(plots)/sizeof(int);
    int k = 8;
    housing(plots,n,k); 

    return 0;
}


