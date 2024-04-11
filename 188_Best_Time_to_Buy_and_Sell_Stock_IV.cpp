class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int len=prices.size();
        if(len==1)return 0;
        int dp[len+1][k+1];
        memset(dp,0,sizeof(dp));
        int minPrevPrices[len];
        memset(minPrevPrices,INT_MAX,sizeof(minPrevPrices));
        for(int i=1;i<=k;i++){
            int min_so_far=prices[0]-dp[0][i-1];
            for(int j=1;j<len;j++){
                minPrevPrices[j]=min_so_far;
                if(prices[j]-dp[j][i-1]<min_so_far)min_so_far=prices[j]-dp[j][i-1];
            }
            for(int j=2;j<=len;j++){
                dp[j][i]=max(dp[j-1][i],prices[j-1]-minPrevPrices[j-1]);
            }
        }
        return dp[len][k];
    }
};