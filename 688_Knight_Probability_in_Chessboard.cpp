class Solution {
public:
    int dir[8][2]={{-2,-1},{-2,1},{-1,-2},{-1,2},{1,-2},{1,2},{2,-1},{2,1}};
    double DP(vector<vector<vector<double>>>& dp, int row, int column, int k){
        if(dp[row][column][k]!=-1.0){
            return dp[row][column][k];
        }
        if(k==0){
            return dp[row][column][k]=1.0;
        }
        int n=dp.size();
        double ans=0;
        for(int i=0;i<8;i++){
            int x=row+dir[i][0],y=column+dir[i][1];
            if(x>=0 && x<n && y>=0 && y<n){
                ans+=DP(dp,x,y,k-1);
            }
        }
        return dp[row][column][k]=ans;
    }
    double knightProbability(int n, int k, int row, int column) {
        if(k==0)return 1.0;
        vector<vector<vector<double>>>dp(n,vector<vector<double>>(n,vector<double>(k+1,-1)));
        double ans=DP(dp,row,column,k);
        for(int i=0;i<k;i++){
            ans/=8.0;
        }
        return ans;
    }
};