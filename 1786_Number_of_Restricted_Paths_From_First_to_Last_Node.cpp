class Solution {
public:
    int DFS(vector<int>& dist, vector<pair<int,int>>adj[], int dp[], int idx, int n){
        if(idx==n-1)return dp[idx]=1;
        if(dp[idx]!=-1)return dp[idx];
        int ans=0;
        for(int i=0;i<adj[idx].size();i++){
            if(dist[adj[idx][i].first]<dist[idx]){
                ans=(ans+DFS(dist,adj,dp,adj[idx][i].first,n))%1000000007;
            }
        }
        return dp[idx]=ans;
    }
    int countRestrictedPaths(int n, vector<vector<int>>& edges) {
        vector<pair<int,int>>adj[n];
        for(int i=0;i<edges.size();i++){
            adj[edges[i][0]-1].push_back({edges[i][1]-1,edges[i][2]});
            adj[edges[i][1]-1].push_back({edges[i][0]-1,edges[i][2]});
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        vector<int>dist(n,INT_MAX);
        dist[n-1]=0;
        pq.push({0,n-1});
        while(!pq.empty()){
            pair<int,int>p=pq.top();
            pq.pop();
            int min_dist=p.first;
            int min_idx=p.second;
            for(int j=0;j<adj[min_idx].size();j++){
                if(min_dist+adj[min_idx][j].second<dist[adj[min_idx][j].first]){
                    dist[adj[min_idx][j].first]=min_dist+adj[min_idx][j].second;
                    pq.push({dist[adj[min_idx][j].first],adj[min_idx][j].first});
                }
            }
        }
        int dp[n];
        memset(dp,-1,sizeof(dp));
        return DFS(dist,adj,dp,0,n);
    }
};