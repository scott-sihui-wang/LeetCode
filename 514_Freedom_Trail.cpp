class Solution {
public:
    int DP(string key, string ring, int idx_k,int idx_r,unordered_map<char,vector<int>>& positions,vector<vector<int>>& dp){
        if(idx_k==key.size())return 0;
        if(dp[idx_k][idx_r]!=-1){
            return dp[idx_k][idx_r];
        }
        vector<int> dest=positions[key[idx_k]];
        int ans=INT_MAX;
        for(int i=0;i<dest.size();i++){
            int dist1=abs(idx_r-dest[i]);
            int dist2=ring.size()-dist1;
            ans=min(ans,DP(key,ring,idx_k+1,dest[i],positions,dp)+min(dist1,dist2)+1);
        }
        return dp[idx_k][idx_r]=ans;
    }
    int findRotateSteps(string ring, string key) {
        unordered_map<char,vector<int>>positions;
        for(int i=0;i<ring.size();i++){
            positions[ring[i]].push_back(i);
        }
        vector<vector<int>>dp(key.size(),vector<int>(ring.size(),-1));
        return DP(key,ring,0,0,positions,dp);
    }
};