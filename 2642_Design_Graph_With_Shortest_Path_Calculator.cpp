class Graph {
public:
    int* dist;
    vector<pair<int,int>>* adj;
    int sz;
    Graph(int n, vector<vector<int>>& edges) {
        sz=n;
        dist=new int[n];
        adj=new vector<pair<int,int>>[n];
        for(int i=0;i<edges.size();i++){
            adj[edges[i][0]].push_back({edges[i][1],edges[i][2]});
        }
    }
    
    void addEdge(vector<int> edge) {
        adj[edge[0]].push_back({edge[1],edge[2]});
    }
    
    int shortestPath(int node1, int node2) {
        for(int i=0;i<sz;i++){
            dist[i]=INT_MAX;
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        dist[node1]=0;
        pq.push({0,node1});
        while(!pq.empty()){
            pair<int,int>p=pq.top();
            pq.pop();
            for(int i=0;i<adj[p.second].size();i++){
                if(dist[adj[p.second][i].first]>dist[p.second]+adj[p.second][i].second){
                    dist[adj[p.second][i].first]=dist[p.second]+adj[p.second][i].second;
                    pq.push({dist[adj[p.second][i].first],adj[p.second][i].first});
                }
            }
        }
        return dist[node2]==INT_MAX?-1:dist[node2];
    }
};

/**
 * Your Graph object will be instantiated and called as such:
 * Graph* obj = new Graph(n, edges);
 * obj->addEdge(edge);
 * int param_2 = obj->shortestPath(node1,node2);
 */