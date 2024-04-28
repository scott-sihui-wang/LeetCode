class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n=matrix.size();
        if(n==1)return matrix[0][0];
        int dp[n][n];
        int ans=INT_MAX;
        memset(dp,0,sizeof(dp));
        for(int i=0;i<n;i++){
            dp[n-1][i]=matrix[n-1][i];
        }
        for(int i=n-2;i>=0;i--){
            dp[i][0]=matrix[i][0]+min(dp[i+1][0],dp[i+1][1]);
            if(i==0)ans=min(ans,dp[i][0]);
            for(int j=1;j<n-1;j++){
                dp[i][j]=matrix[i][j]+min(dp[i+1][j-1],min(dp[i+1][j],dp[i+1][j+1]));
                if(i==0)ans=min(ans,dp[i][j]);
            }
            dp[i][n-1]=matrix[i][n-1]+min(dp[i+1][n-2],dp[i+1][n-1]);
            if(i==0)ans=min(ans,dp[i][n-1]);
        }
        return ans;
    }
};