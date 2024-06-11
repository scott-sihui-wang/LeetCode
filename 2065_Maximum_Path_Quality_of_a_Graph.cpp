class Solution {
public:
    void DFS(vector<int>& values,vector<pair<int,int>> adj[],int visited[],int idx,int sum, int time, int& maxSum, int maxTime){
        if(visited[idx]==0){
            sum+=values[idx];
        }
        visited[idx]++;
        if(idx==0){
            maxSum=max(maxSum,sum);
        }
        for(int i=0;i<adj[idx].size();i++){
            if(time+adj[idx][i].second<=maxTime){
                DFS(values,adj,visited,adj[idx][i].first,sum,time+adj[idx][i].second,maxSum,maxTime);
            }
        }
        visited[idx]--;
    }
    int maximalPathQuality(vector<int>& values, vector<vector<int>>& edges, int maxTime) {
        int n=values.size();
        int visited[n];
        memset(visited,0,sizeof(visited));
        vector<pair<int,int>> adj[n];
        for(int i=0;i<edges.size();i++){
            adj[edges[i][0]].push_back({edges[i][1],edges[i][2]});
            adj[edges[i][1]].push_back({edges[i][0],edges[i][2]});
        }
        int ans=0;
        DFS(values,adj,visited,0,0,0,ans,maxTime);
        return ans;
    }
};