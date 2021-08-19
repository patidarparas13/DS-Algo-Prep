class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n =prices.size();
        if(prices.size()==1){
            return 0;
        }
        int pmin[n+1],prefix_profit[n+1];
        //Prefix Min Array
        pmin[0]=prices[0];
        for(int i=1;i<n;i++){
            pmin[i] = min(pmin[i-1],prices[i]);
        }
        
        //Calculating Prefix Profit
        prefix_profit[0] = 0;
        for(int i=1;i<n;i++){
            int new_profit = prices[i]-pmin[i-1];
            prefix_profit[i] = max(new_profit,prefix_profit[i-1]);
        }
        
        int SMAX[n+1], suffix_profit[n+1];
        //Suffix Max Array
        SMAX[n-1]=prices[n-1];
        for(int i=n-2;i>=0;i--){
            SMAX[i] = max(prices[i],SMAX[i+1]);
        }
        
        //Calculating Suffix Profit
        suffix_profit[n-1]=0;
        for(int i=n-2;i>=0;i--){
            int new_profit = SMAX[i+1] - prices[i];
            suffix_profit[i] = max(new_profit,suffix_profit[i+1]);
        }
        
        int profit = suffix_profit[0];
        for(int i=1;i<n;i++){
            int profit_with_two_trans = prefix_profit[i-1]+suffix_profit[i];
            profit= max(profit,profit_with_two_trans);
        }
        
        
        
        return profit;
    }
};
