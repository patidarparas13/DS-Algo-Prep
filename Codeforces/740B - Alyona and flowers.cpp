
#include <iostream>
#include<vector>
using namespace std;

int main() {
	int n,k;
    cin>>n>>k;
    int arr[n];
    for(int i=0;i<n;i++) cin>>arr[i];
    vector<pair<int,int>> v;
    for(int i=0;i<k;i++){
        int x,y;
        cin>>x>>y;
        v.push_back({x,y});
    }
    int prefix_sum[n+1];
    prefix_sum[0] = arr[0];
    for(int i=1;i<n;i++){
        prefix_sum[i] =arr[i]+prefix_sum[i-1];
        // cout<<">"<<prefix_sum[i]<<endl;
    }
    int totalHappiness = 0;
    for(int i=0;i<k;i++){
        int x,y;

        x = v[i].first-1;
        y = v[i].second-1;
                        // cout<<"x:"<<x<<",y:"<<y<<endl;

        int currentSum = x> 0 ? prefix_sum[y] - prefix_sum[x-1]:prefix_sum[y];
        // cout<<currentSum<<endl;
        if(currentSum>0){
            totalHappiness += currentSum;
        }
    }
    cout<<totalHappiness<<endl;
    
	return 0;
}

