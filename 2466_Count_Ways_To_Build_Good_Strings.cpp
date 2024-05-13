class Solution {
public:
    long long MOD=1000000007;
    long long solve(long long dp[],int i,int zero,int one){
        if(i<0)return 0;
        if(i==0)return dp[0]=1;
        if(dp[i]!=-1)return dp[i]%MOD;
        return dp[i]=solve(dp,i-zero,zero,one)%MOD+solve(dp,i-one,zero,one)%MOD;
    }
    int countGoodStrings(int low, int high, int zero, int one) {
        long long dp[high+1];
        memset(dp,-1,sizeof(dp));
        long long ans=0;
        for(int i=high;i>=low;i--){
            ans+=solve(dp,i,zero,one)%MOD;
        }
        return ans%MOD;
    }
};