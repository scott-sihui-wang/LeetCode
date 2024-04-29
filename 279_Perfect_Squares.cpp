class Solution {
public:
    int DP(int n,int* dp,vector<int>& squares){
        if(dp[n]!=-1)return dp[n];
        int ans=INT_MAX;
        int i=0;
        while(i<squares.size() && n-squares[i]>0){
            ans=min(ans,1+DP(n-squares[i],dp,squares));
            i++;
        }
        dp[n]=ans;
        return ans;
    }
    int numSquares(int n) {
        int dp[n+1];
        vector<int> squares;
        for(int i=1;i<=n;i++){
            dp[i]=-1;
        }
        for(int i=1;i*i<=n;i++){
            int sq=i*i;
            dp[sq]=1;
            squares.push_back(sq);
        }
        return DP(n,dp,squares);
    }
};