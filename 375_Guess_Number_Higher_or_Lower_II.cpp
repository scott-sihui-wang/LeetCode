class Solution {
public:
    int solve(vector<vector<int>>&dp,int i,int j){
        if(i<0 || i>=dp.size() || j<0 || j>=dp[0].size())return 0;
        if(i>=j)return dp[i][j]=0;
        if(dp[i][j]!=-1)return dp[i][j];
        int ans=INT_MAX;
        for(int k=i;k<=j;k++){
            ans=min(ans,k+1+max(solve(dp,i,k-1),solve(dp,k+1,j)));
        }
        return dp[i][j]=ans;
    }
    int getMoneyAmount(int n) {
        vector<vector<int>>dp(n,vector<int>(n,-1));
        return solve(dp,0,n-1);
    }
};