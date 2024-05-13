class Solution {
public:
    int numTilings(int n) {
        if(n==1){
            return 1;
        }
        else if(n==2){
            return 2;
        }
        else{
            long long MOD=1000000007;
            long long dp[n][2];
            dp[0][0]=1;
            dp[0][1]=1;
            dp[1][0]=2;
            dp[1][1]=2;
            for(int i=2;i<n;i++){
                dp[i][0]=(dp[i-1][0]%MOD+dp[i-2][0]%MOD+2*dp[i-2][1]%MOD)%MOD;
                dp[i][1]=(dp[i-1][0]%MOD+dp[i-1][1]%MOD)%MOD;
            }
            return (dp[n-1][0])%MOD;
        }
    }
};