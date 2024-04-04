class Solution {
public:
    void dfs(int n,int begin,bool* vis,vector<vector<int> >&adj){
        for(int i=0;i<adj[begin].size();i++){
            if(vis[adj[begin][i]]==false){
                vis[adj[begin][i]]=true;
                dfs(n,adj[begin][i],vis,adj);
            }
        }
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
        int len=connections.size();
        if(len<n-1){
            return -1;
        }
        else{
            bool vis[n];
            for(int i=0;i<n;i++){
                vis[i]=false;
            }
            vector<vector<int> > adj;
            for(int i=0;i<n;i++){
                vector<int> tmp;
                adj.push_back(tmp);
            }
            for(int i=0;i<len;i++){
                adj[connections[i][0]].push_back(connections[i][1]);
                adj[connections[i][1]].push_back(connections[i][0]);
            }
            int cnt=0;
            for(int i=0;i<n;i++){
                if(vis[i]==false){
                    cnt++;
                    vis[i]=true;
                    dfs(n,i,vis,adj);
                }
            }
            return cnt-1;
        }
    }
};