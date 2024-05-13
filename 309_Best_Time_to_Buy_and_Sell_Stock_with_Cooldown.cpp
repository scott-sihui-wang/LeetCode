class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        int dp[n+2];
        memset(dp,0,sizeof(dp));
        int M=INT_MIN;
        for(int i=3;i<=n+1;i++){
            M=max(M,dp[i-3]-prices[i-3]);
            dp[i]=max(dp[i-1],prices[i-2]+M);
        }
        return dp[n+1];
    }
};