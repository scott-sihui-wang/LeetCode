class Solution {
public:
    long long MOD=1000000007;
    int kInversePairs(int n, int k) {
        vector<vector<int>>dp(n+1,vector<int>(k+1,0));
        dp[0][0]=1;
        for(int i=1;i<=n;i++){
            for(int j=0;j<=k;j++){
                long long val=0;
                for(int k=0;k<=min(j,i-1);k++){
                    val+=dp[i-1][j-k];
                    val=val%MOD;
                }
                dp[i][j]=val;
            }
        }
        return dp[n][k];
    }
};