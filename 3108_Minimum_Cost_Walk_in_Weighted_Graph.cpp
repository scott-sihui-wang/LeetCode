class Solution {
public:
    void DFS(vector<pair<int,int>>adj[],int component_id[],int v,int id){
        for(int i=0;i<adj[v].size();i++){
            if(component_id[adj[v][i].first]==-1){
                component_id[adj[v][i].first]=id;
                DFS(adj,component_id,adj[v][i].first,id);
            }
        }
    }
    vector<int> minimumCost(int n, vector<vector<int>>& edges, vector<vector<int>>& query) {
        int component_id[n];
        memset(component_id,-1,sizeof(component_id));
        vector<pair<int,int>>adj[n];
        for(int i=0;i<edges.size();i++){
            adj[edges[i][0]].push_back({edges[i][1],edges[i][2]});
            adj[edges[i][1]].push_back({edges[i][0],edges[i][2]});
        }
        int id=0;
        for(int i=0;i<n;i++){
            if(component_id[i]==-1){
                component_id[i]=id;
                DFS(adj,component_id,i,id);
            }
            id++;
        }
        int min_wt[id];
        for(int i=0;i<id;i++){
            min_wt[i]=INT_MAX;
        }
        for(int i=0;i<edges.size();i++){
            min_wt[component_id[edges[i][0]]]&=edges[i][2];
        }
        vector<int>ans(query.size());
        for(int i=0;i<query.size();i++){
            if(component_id[query[i][0]]!=component_id[query[i][1]]){
                ans[i]=-1;
            }
            else{
                ans[i]=min_wt[component_id[query[i][0]]];
            }
        }
        return ans;
    }
};