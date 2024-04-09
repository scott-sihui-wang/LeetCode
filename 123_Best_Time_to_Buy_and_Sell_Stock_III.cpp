class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int idx=0,len=prices.size();
        if(len==1)return 0;
        int dp1[len+1],dp2[len+1];
        memset(dp1,0,sizeof(dp1));
        memset(dp2,0,sizeof(dp2));
        int minPrevPrices[len];
        memset(minPrevPrices,INT_MAX,sizeof(minPrevPrices));
        int min_so_far=prices[0];
        for(int i=1;i<len;i++){
            minPrevPrices[i]=min_so_far;
            if(prices[i]<min_so_far)min_so_far=prices[i];
        }
        for(int i=2;i<=len;i++){
            dp1[i]=max(dp1[i-1],prices[i-1]-minPrevPrices[i-1]);
        }
        min_so_far=prices[0]-dp1[0];
        for(int i=1;i<len;i++){
            minPrevPrices[i]=min_so_far;
            if(prices[i]-dp1[i]<min_so_far)min_so_far=prices[i]-dp1[i];
        }
        for(int i=2;i<=len;i++){
            dp2[i]=max(dp2[i-1],prices[i-1]-minPrevPrices[i-1]);
        }
        return dp2[len];
    }
};