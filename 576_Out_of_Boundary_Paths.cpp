class Solution {
public:
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        int dp[m][n];
        memset(dp,0,sizeof(dp));
        int MOD=1000000007;
        dp[startRow][startColumn]=1;
        int ans=0;
        for(int i=1;i<=maxMove;i++){
            for(int p=0;p<m;p++){
                ans+=(dp[p][0]+dp[p][n-1])%MOD;
                ans=ans%MOD;
            }
            for(int q=0;q<n;q++){
                ans+=(dp[0][q]+dp[m-1][q])%MOD;
                ans=ans%MOD;
            }
            if(i==maxMove)break;
            int next_dp[m][n];
            memset(next_dp,0,sizeof(next_dp));
            for(int p=0;p<m;p++){
                for(int q=0;q<n;q++){
                    next_dp[p][q]=(((p>0?dp[p-1][q]:0)+(p<m-1?dp[p+1][q]:0))%MOD+((q>0?dp[p][q-1]:0)+(q<n-1?dp[p][q+1]:0))%MOD)%MOD;
                }
            }
            for(int p=0;p<m;p++){
                for(int q=0;q<n;q++){
                    dp[p][q]=next_dp[p][q];
                }
            }
        }
        return ans;
    }
};