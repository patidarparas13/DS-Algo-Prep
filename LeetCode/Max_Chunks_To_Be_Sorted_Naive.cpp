class Solution {
public:
    bool canBeChunked(vector<int> arr,int i,int j){
        int count = 0;
        for(int k=i;k<=j;k++){
            if(arr[k]>=i and arr[k]<=j){
                count++;
            }
        }
        
        if(count==(j-i+1)){
            return true;
        }
        return false;
    }
    int maxChunksToSorted(vector<int>& arr) {
        int i=0;
        int n = arr.size();
        int chunks=0;
        while(i<n){
            int j=i;
            for(;j<n;j++){
                if(canBeChunked(arr,i,j)) break;
            }
            chunks++;
            i = j+1;
        }
        return chunks;
    }
};
