class Solution {
public:
    int integerBreak(int n) {
        int dp[n];
        dp[0]=1;
        dp[1]=1;
        for(int i=2;i<n;i++){
            int M=0;
            for(int j=1;j<=i;j++){
                M=max(M,j*max(dp[i-j],i-j+1));
            }
            dp[i]=M;
        }
        return dp[n-1];
    }
};