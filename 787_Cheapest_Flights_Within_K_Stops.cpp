class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<pair<int,int>>adj[n];
        vector<int>dist(n,INT_MAX);
        bool visited[n];
        memset(visited,false,sizeof(visited));
        for(int i=0;i<flights.size();i++){
            adj[flights[i][0]].push_back({flights[i][1],flights[i][2]});
        }
        dist[src]=0;
        for(int i=0;i<=k;i++){
            queue<pair<int,int>>q;
            int minV=-1,minDist=INT_MAX;
            for(int j=0;j<n;j++){
                if(visited[j]==false){
                    if(dist[j]<INT_MAX){
                        q.push({j,dist[j]});
                    }
                    if(dist[j]<minDist){
                        minDist=dist[j];
                        minV=j;
                    }
                }
            }
            while(!q.empty()){
                pair v=q.front();
                q.pop();
                for(int m=0;m<adj[v.first].size();m++){
                    if(dist[adj[v.first][m].first]>v.second+adj[v.first][m].second){
                        dist[adj[v.first][m].first]=v.second+adj[v.first][m].second;
                    }
                }
            }
            if(minV!=-1){
                visited[minV]=true;
            }
        }
        return dist[dst]==INT_MAX?-1:dist[dst];
    }
};