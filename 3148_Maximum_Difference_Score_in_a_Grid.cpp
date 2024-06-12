class Solution {
public:
    int maxScore(vector<vector<int>>& grid) {
        int m=grid.size(),n=grid[0].size();
        int dp[m][n];
        memset(dp,0,sizeof(dp));
        dp[m-1][n-2]=grid[m-1][n-1]-grid[m-1][n-2];
        int ans=dp[m-1][n-2];
        dp[m-2][n-1]=grid[m-1][n-1]-grid[m-2][n-1];
        ans=max(ans,dp[m-2][n-1]);
        for(int i=n-3;i>=0;i--){
            dp[m-1][i]=grid[m-1][i+1]-grid[m-1][i]+max(0,dp[m-1][i+1]);
            ans=max(ans,dp[m-1][i]);
        }
        for(int i=m-3;i>=0;i--){
            dp[i][n-1]=grid[i+1][n-1]-grid[i][n-1]+max(0,dp[i+1][n-1]);
            ans=max(ans,dp[i][n-1]);
        }
        for(int i=m-2;i>=0;i--){
            for(int j=n-2;j>=0;j--){
                dp[i][j]=max(grid[i+1][j]-grid[i][j]+max(0,dp[i+1][j]),grid[i][j+1]-grid[i][j]+max(0,dp[i][j+1]));
                ans=max(ans,dp[i][j]);
            }
        }
        return ans;
    }
};