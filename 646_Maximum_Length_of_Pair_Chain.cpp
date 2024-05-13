class Solution {
public:
    int solve(int dp[],int n,int idx,vector<pair<int,int>>&p){
        if(dp[idx]!=-1)return dp[idx];
        int ans=0;
        for(int i=idx+1;i<n;i++){
            if(p[idx].second<p[i].first){
                ans=max(ans,solve(dp,n,i,p));
            }
        }
        dp[idx]=ans+1;
        return dp[idx];
    }
    int findLongestChain(vector<vector<int>>& pairs) {
        int n=pairs.size();
        vector<pair<int,int>>p;
        for(int i=0;i<n;i++){
            p.push_back({pairs[i][0],pairs[i][1]});
        }
        sort(p.begin(),p.end());
        int dp[n];
        memset(dp,-1,sizeof(dp));
        int ans=0;
        for(int i=0;i<n;i++){
            ans=max(ans,solve(dp,n,i,p));
        }
        return ans;
    }
};