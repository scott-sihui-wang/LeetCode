class Solution {
public:
    void DFS(int src,vector<vector<int>>& conn,vector<vector<int>>& dir,bool* visited,int& cnt){
        for(int i=0;i<conn[src].size();i++){
            if(visited[conn[src][i]]==false){
                visited[conn[src][i]]=true;
                if(dir[src][i]==1){
                    ++cnt;
                }
                DFS(conn[src][i],conn,dir,visited,cnt);
                visited[conn[src][i]]=false;
            }
        }
    }
    int minReorder(int n, vector<vector<int>>& connections) {
        vector<vector<int>> undirected_connections(n,vector<int>());
        vector<vector<int>> directions(n,vector<int>());
        for(int i=0;i<connections.size();i++){
            undirected_connections[connections[i][0]].push_back(connections[i][1]);
            undirected_connections[connections[i][1]].push_back(connections[i][0]);
            directions[connections[i][0]].push_back(1);
            directions[connections[i][1]].push_back(-1);
        }
        bool visited[n];
        memset(visited,false,sizeof(visited));
        visited[0]=true;
        int cnt=0;
        DFS(0,undirected_connections,directions,visited,cnt);
        return cnt;
    }
};