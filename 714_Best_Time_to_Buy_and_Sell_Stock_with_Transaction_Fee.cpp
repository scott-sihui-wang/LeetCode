class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n=prices.size();
        int dp[n+1];
        memset(dp,0,sizeof(dp));
        int M=INT_MIN;
        for(int i=2;i<=n;i++){
            M=max(M,dp[i-2]-prices[i-2]);
            dp[i]=max(dp[i-1],prices[i-1]-fee+M);
        }
        return dp[n];
    }
};