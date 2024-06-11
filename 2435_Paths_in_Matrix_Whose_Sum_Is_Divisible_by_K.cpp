class Solution {
public:
    int MOD=1000000007;
    long long dp(vector<vector<int>>& grid,vector<vector<vector<long long>>>& DP,int m,int n,int k, int mod){
        if( m<0 || n<0 ) return 0;
        if(m==0 && n==0){
            if(k==grid[0][0]%mod){
                return DP[0][0][grid[0][0]%mod]=1;
            }
            else{
                return DP[0][0][k]=0;
            }
        } 
        if(DP[m][n][k]!=INT_MIN)return DP[m][n][k];
        return DP[m][n][k]=((dp(grid,DP,m-1,n,(k-grid[m][n]>=0?(k-grid[m][n])%mod:(mod+(k-grid[m][n])%mod))%mod,mod))%MOD+(dp(grid,DP,m,n-1,(k-grid[m][n]>=0?(k-grid[m][n])%mod:(mod+(k-grid[m][n])%mod))%mod,mod))%MOD)%MOD;
    }
    int numberOfPaths(vector<vector<int>>& grid, int k) {
        int m=grid.size(),n=grid[0].size();
        vector<vector<vector<long long>>>DP(m,vector<vector<long long>>(n,vector<long long>(k,INT_MIN)));
        return dp(grid,DP,m-1,n-1,0,k);
    }
};