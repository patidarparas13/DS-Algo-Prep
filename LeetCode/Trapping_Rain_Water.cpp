class Solution {
public:
    int trap(vector<int>& height) {
        if(height.empty())
                return 0;
        int n = height.size();
        int min_height=0;
        int waterTrapped = 0;
        vector<int>PMAX(n);
        vector<int>SMAX(n);
        PMAX[0] = height[0];
        SMAX[n-1] = height[n-1];
        for(int i=1;i<n;i++){
            PMAX[i] = max(PMAX[i-1],height[i]);
        }
        for(int i=n-2;i>=0;i--){
            SMAX[i] = max(SMAX[i+1],height[i]);
        }
        for(int i=1;i<n-1;i++){
             waterTrapped += min(PMAX[i],SMAX[i])-height[i];
        }
        return waterTrapped;
    }
};
