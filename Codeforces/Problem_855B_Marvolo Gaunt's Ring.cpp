
#include <iostream>
#include<climits>
using namespace std;



int main() {
	// your code goes here
    long long n,p,q,r;
    cin>>n>>p>>q>>r;
    long long arr[n];
    for(long long i=0;i<n;i++){
        cin>>arr[i];
    }
long long max_so_far = LLONG_MIN;
    long long PMAX[n]={0};
    long long SMAX[n] = {0};
    PMAX[0] = p*arr[0];
    SMAX[n-1] = r*arr[n-1];
    for(long long i=1;i<n;i++){
        PMAX[i] = max(PMAX[i-1],p*arr[i]);
    }
    for(long long i=n-2;i>=0;i--){
        SMAX[i] = max(SMAX[i+1],r*arr[i]);
    }
    for(long long i=0;i<n;i++){
        max_so_far = max(max_so_far,PMAX[i]+q*arr[i]+SMAX[i]);
    }
    cout<<max_so_far;
	return 0;
}

