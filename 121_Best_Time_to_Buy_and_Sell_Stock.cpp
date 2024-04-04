class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int max_profit=0;
        int max_val=0;
        int len=prices.size();
        for(int i=len-2;i>=0;i--){
            max_val=max(max_val,prices[i+1]);
            max_profit=max(max_profit,max_val-prices[i]);
        }
        return max_profit;
    }
};