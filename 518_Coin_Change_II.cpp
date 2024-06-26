class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n=coins.size();
        int dp[n+1][amount+1];
        for(int i=0;i<=n;i++){
            dp[i][0]=1;
        }
        for(int i=1;i<=amount;i++){
            dp[0][i]=0;
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=amount;j++){
                dp[i][j]=dp[i-1][j];
                int k=j-coins[i-1];
                while(k>=0){
                    dp[i][j]+=dp[i-1][k];
                    k-=coins[i-1];
                }
            }
        }
        return dp[n][amount];
    }
};