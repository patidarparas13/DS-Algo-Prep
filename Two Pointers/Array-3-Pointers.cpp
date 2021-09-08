//Link: https://www.interviewbit.com/problems/array-3-pointers/#
//Sol Link: https://www.geeksforgeeks.org/find-three-closest-elements-from-given-three-sorted-arrays/

int Solution::minimize(const vector<int> &A, const vector<int> &B, const vector<int> &C) {
    int diff = INT_MAX;

    int i=0,j=0,k=0;
    while(i<A.size() && j<B.size() && k<C.size()){

        int minimum = min(A[i],min(B[j],C[k]));
        int maximum = max(A[i],max(B[j],C[k]));
        if(maximum-minimum<diff){
            diff = maximum-minimum;
        }
        if(diff==0) break;
        if(A[i]==minimum) i++;
        else if(B[j]==minimum) j++;
        else k++;
    }

    return diff;

}
