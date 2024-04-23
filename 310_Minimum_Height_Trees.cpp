class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        int degree[n];
        bool visited[n];
        vector<vector<int>>adj(n,vector<int>());
        memset(degree,0,sizeof(degree));
        memset(visited,false,sizeof(visited));
        for(int i=0;i<edges.size();i++){
            degree[edges[i][0]]++;
            degree[edges[i][1]]++;
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        queue<int> q;
        int num_to_visit=n;
        while(num_to_visit>2){
            for(int i=0;i<n;i++){
                if(visited[i]==false && degree[i]==1){
                    q.push(i);
                    degree[i]--;
                    visited[i]=true;
                    num_to_visit--;
                }
            }
            while(!q.empty()){
                int elem=q.front();
                q.pop();
                for(int j=0;j<adj[elem].size();j++){
                    if(visited[adj[elem][j]]==false){
                        degree[adj[elem][j]]--;
                    }
                }
            }
        }
        vector<int> ans;
        for(int i=0;i<n;i++){
            if(visited[i]==false){
                ans.push_back(i);
            }
        }
        return ans;
    }
};
