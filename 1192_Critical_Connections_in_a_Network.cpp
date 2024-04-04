class Solution {
public:
    void dfs(int cur,int& time,bool vis[],int disc[],int low[],int parent[],vector<vector<int> >&adj,vector<vector<int> >&sol){
        ++time;
        vis[cur]=true;
        disc[cur]=time;
        low[cur]=time;
        int len=adj[cur].size();
        for(int i=0;i<len;i++){
            if(vis[adj[cur][i]]==false){
                parent[adj[cur][i]]=cur;
                dfs(adj[cur][i],time,vis,disc,low,parent,adj,sol);
                low[cur]=min(low[cur],low[adj[cur][i]]);
                if(low[adj[cur][i]]>disc[cur]){
                    vector<int>tmp;
                    tmp.push_back(cur);
                    tmp.push_back(adj[cur][i]);
                    sol.push_back(tmp);
                }
            }
            else if(adj[cur][i]!=parent[cur]){
                low[cur]=min(low[cur],disc[adj[cur][i]]);
            }
        }
    }
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        bool vis[n];
        for(int i=0;i<n;i++){
            vis[i]=false;
        }
        int time=0;
        int disc[n];
        int low[n];
        int parent[n];
        int len=connections.size();
        vector<vector<int> >adj(n,vector<int>(0));
        for(int i=0;i<len;i++){
            adj[connections[i][0]].push_back(connections[i][1]);
            adj[connections[i][1]].push_back(connections[i][0]);
        }
        vector<vector<int> >sol;
        for(int i=0;i<n;i++){
            if(vis[i]==false){
                dfs(i,time,vis,disc,low,parent,adj,sol);
            }
        }
        return sol;
    }
};