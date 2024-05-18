class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int n=nums.size();
        int dp[n+2][n+2];
        memset(dp,0,sizeof(dp));
        int n_expand[n+2];
        n_expand[0]=1;
        n_expand[n+1]=1;
        for(int i=1;i<=n;i++){
            n_expand[i]=nums[i-1];
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n+1-i;j++){
                int res=0;
                for(int k=j-1;k<j+i-1;k++){
                    res=max(res,dp[j][k]+n_expand[j-1]*n_expand[k+1]*n_expand[i+j]+dp[k+2][i+j-1]);
                }
                dp[j][j+i-1]=res;
            }
        }
        return dp[1][n];
    }
};