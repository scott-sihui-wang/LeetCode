class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int m=matrix.size(),n=matrix[0].size();
        int p=min(m,n);
        int ans=0;
        int dp[m+1][n+1];
        memset(dp,0,sizeof(dp));
        for(int i=1;i<=p;i++){
            for(int j=m-i;j>=0;j--){
                if(matrix[j][n-i]=='0'){
                    dp[j][n-i]=0;
                }
                else{
                    dp[j][n-i]=1+min(min(dp[j][n-i+1],dp[j+1][n-i]),dp[j+1][n-i+1]);
                }
                ans=max(ans,dp[j][n-i]);
            }
            for(int k=n-i;k>=0;k--){
                if(matrix[m-i][k]=='0'){
                    dp[m-i][k]=0;
                }
                else{
                    dp[m-i][k]=1+min(min(dp[m-i][k+1],dp[m-i+1][k]),dp[m-i+1][k+1]);
                }
                ans=max(ans,dp[m-i][k]);
            }
        }
        return ans*ans;
    }
};