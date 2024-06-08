class Solution {
public:
    int dp(vector<vector<int>>& grid, vector<vector<vector<int>>>& DP, int r1, int c1, int r2){
        int n=grid.size();
        if(r1>=n || r2>=n ||c1>=n || r1+c1-r2>=n || grid[r1][c1]==-1 || grid[r2][r1+c1-r2]==-1)return INT_MIN;
        if(DP[r1][c1][r2]!=INT_MIN)return DP[r1][c1][r2];
        if(r1==n-1 && c1==n-1)return DP[r1][c1][r1]=grid[r1][c1];
        int ans=grid[r1][c1];
        if(r1!=r2){
            ans+=grid[r2][r1+c1-r2];
        }
        ans+=max(dp(grid,DP,r1+1,c1,r2+1),max(dp(grid,DP,r1+1,c1,r2),max(dp(grid,DP,r1,c1+1,r2+1),dp(grid,DP,r1,c1+1,r2))));
        return DP[r1][c1][r2]=ans;
    }
    int cherryPickup(vector<vector<int>>& grid) {
        int n=grid.size();
        vector<vector<vector<int>>>DP(n,vector<vector<int>>(n,vector<int>(n,INT_MIN)));
        return max(0,dp(grid,DP,0,0,0));
    }
};