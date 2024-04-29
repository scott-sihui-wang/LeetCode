class Solution {
public:
    void DFS(int src,vector<vector<int>>& adj,bool *visited,vector<int>& res,vector<int>& cnt){
        for(int i=0;i<adj[src].size();i++){
            if(visited[adj[src][i]]==false){
                visited[adj[src][i]]=true;
                DFS(adj[src][i],adj,visited,res,cnt);
                cnt[src]+=cnt[adj[src][i]];
                res[src]+=res[adj[src][i]]+cnt[adj[src][i]];
            }
        }
    }
    void DFS2(int src,vector<vector<int>>& adj,bool *visited,vector<int>& res,vector<int>& cnt,int n){
        for(int i=0;i<adj[src].size();i++){
            if(visited[adj[src][i]]==false){
                visited[adj[src][i]]=true;
                res[adj[src][i]]=res[src]+n-2*cnt[adj[src][i]];
                DFS2(adj[src][i],adj,visited,res,cnt,n);
            }
        }
    }
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        vector<int>res(n,0);
        vector<int>cnt(n,1);
        vector<vector<int>>adj(n);
        for(int i=0;i<edges.size();i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        bool visited[n];
        visited[0]=true;
        for(int i=1;i<n;i++){
            visited[i]=false;
        }
        DFS(0,adj,visited,res,cnt);
        visited[0]=true;
        for(int i=1;i<n;i++){
            visited[i]=false;
        }
        DFS2(0,adj,visited,res,cnt,n);
        return res;
    }
};